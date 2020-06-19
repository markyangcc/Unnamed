#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <fstream>
#pragma comment(lib, "ws2_32") //指定连接到网络应用和internet
#define IO_RCVALL _WSAIOW(IOC_VENDOR, 1)

typedef struct IP_HEAD
{
    union //定义联合
    {
        unsigned char Version;
        unsigned char HeadLen;
    };
    unsigned char ServiceType;
    unsigned short TotalLen;
    unsigned short Identifier;
    union {
        unsigned short Flags;
        unsigned short FragOffset;
    };
    unsigned char TimeToLive;
    unsigned char Protocol;
    unsigned short HeadChecksum;
    unsigned int SourceAddr;
    unsigned int DestinAddr;
    unsigned char Options;
} ip_head; //定义IP头部的数据结构

int main(int argc, char *argv[])
{
    using namespace std;

    ofstream outfile("D:\\file1.txt", ios::out);

    if (argc != 2)
    {
        cout << endl
             << "请以下格式输入命令行:PackParse packet_sum" << endl;
        return 0;
    }
    WSADATA WSAData;
    if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0)
    {
        cout << endl
             << "WSASTartup初始化失败" << endl;
        return 0;
    }
    SOCKET sock = socket(AF_INET, SOCK_RAW, IPPROTO_IP); //三个参分别为通信发生的区字段，套接字的类型，与IP协议
    if (sock == INVALID_SOCKET)
    {
        cout << endl
             << "创建Socket失败!" << endl;
        closesocket(sock);
        WSACleanup();
        //goto exit_clean;
    }
    BOOL flag = TRUE;
    //设置SockRaw这个套接字的ip选项中的IP_HDRINCL(包含首部)
    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (char *)&flag, sizeof(flag)) == SOCKET_ERROR)
    {
        cout << endl
             << "setsockopt操作失败:" << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        //goto exit_clean;
    }
    char hostName[128]; //获取主机名
    if (gethostname(hostName, 100) == SOCKET_ERROR)
    {
        cout << endl
             << "gethostname操作失败:" << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        //goto exit_clean;
    }
    hostent *pHostIP; //获取本地IP
    if ((pHostIP = gethostbyname(hostName)) == NULL)
    {
        cout << endl
             << "gethostbyname操作失败:" << WSAGetLastError() << endl;
        closesocket(sock); //绑定网卡
        WSACleanup();
        //goto exit_clean;
    }
    sockaddr_in host_addr;
    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(6000);
    host_addr.sin_addr = *(in_addr *)pHostIP->h_addr_list[0];
    if (bind(sock, (PSOCKADDR)&host_addr, sizeof(host_addr)) == SOCKET_ERROR)
    {
        cout << endl
             << "bind操作失败:" << WSAGetLastError() << endl;
        closesocket(sock);
        WSACleanup();
        //goto exit_clean;
    }
    DWORD dwBufferLen[10];
    DWORD dwBufferInLen = 1;
    DWORD dwBytesReturned = 0;
    if (WSAIoctl(sock, IO_RCVALL, &dwBufferInLen, sizeof(dwBufferInLen), &dwBufferLen, sizeof(dwBufferLen), &dwBytesReturned, NULL, NULL) == SOCKET_ERROR)
    {
        cout << endl
             << "WSAIoctl操作失败:" << WSAGetLastError() << endl;
        closesocket(sock); //将网卡设为混杂模式，以接受所有数据
        WSACleanup();
        //goto exit_clean;
    }
    cout << endl
         << "开始解析IP包:" << endl;
    char buffer[65535];          //设置缓冲区
    int packsum = atoi(argv[1]); //字符串转换为整形
    for (int i = 0; i < packsum; i++)
    {
        if (recv(sock, buffer, 65535, 0) > 0) //四个参数分别是套接字描述符，缓冲区的地址，缓冲区大小，附加标志
        {
            ip_head ip = *(ip_head *)buffer;
            cout << "-----------------------" << endl;
            cout << "版本:" << (ip.Version >> 4) << endl;             //获取头部长度字段
            cout << "头部长度:" << ((ip.HeadLen & 0x0f) * 4) << endl; //获取头部长度字段
            cout << "服务类型:Priority" << (ip.ServiceType >> 5) << ", Service" << ((ip.ServiceType >> 1) & 0x0f) << endl;
            cout << "总长度:" << ip.TotalLen << endl;                                                                                              //获取总长度字段
            cout << "标识符:" << ip.Identifier << endl;                                                                                            //获取标识字段
            cout << "标志位:" << ((ip.Flags >> 15) & 0x01) << ",DF= " << ((ip.Flags >> 14) & 0x01) << ",Mf=" << ((ip.Flags >> 13) & 0x01) << endl; //获得标志字段
            cout << "片偏移:" << (ip.FragOffset & 0x1fff) << endl;                                                                                 //获取分段偏移字段
            cout << "生存周期:" << (int)ip.TimeToLive << endl;                                                                                     //获取生存时间字段
            cout << "协议:Protocol" << (int)ip.Protocol << endl;                                                                                   //获取协议字段
            cout << "头部校验和:" << ip.HeadChecksum << endl;                                                                                      //获取头校验和字段
            cout << "原地址:" << inet_ntoa(*(in_addr *)&ip.SourceAddr) << endl;                                                                    //获取源IP地址字段
            cout << "目的IP地址:" << inet_ntoa(*(in_addr *)&ip.DestinAddr) << endl;                                                                //获取目的IP地址字段

            outfile << "-----------------------" << endl;
            outfile << "版本:" << (ip.Version >> 4) << endl;
            outfile << "头部长度:" << ((ip.HeadLen & 0x0f) * 4) << endl;
            outfile << "服务类型:Priority" << (ip.ServiceType >> 5) << ", Service" << ((ip.ServiceType >> 1) & 0x0f) << endl;
            outfile << "总长度:" << ip.TotalLen << endl;
            outfile << "标识符:" << ip.Identifier << endl;
            outfile << "标志位:" << ((ip.Flags >> 15) & 0x01) << ",DF= " << ((ip.Flags >> 14) & 0x01) << ",Mf=" << ((ip.Flags >> 13) & 0x01) << endl;
            outfile << "片偏移:" << (ip.FragOffset & 0x1fff) << endl;
            outfile << "生存周期:" << (int)ip.TimeToLive << endl;
            outfile << "协议:Protocol" << (int)ip.Protocol << endl;
            outfile << "头部校验和:" << ip.HeadChecksum << endl;
            outfile << "原地址:" << inet_ntoa(*(in_addr *)&ip.SourceAddr) << endl;
            outfile << "目的IP地址:" << inet_ntoa(*(in_addr *)&ip.DestinAddr) << endl;
        }
    }

    //exit_clean:
    closesocket(sock);
    WSACleanup();

    return 0;
}