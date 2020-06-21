#include <cstdio>
#include <iostream>
#include <Winsock2.h>
#include <pcap.h>

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "wpcap.lib")

using namespace std;

/*定义以太网的协议格式*/
struct ethernet_header
{
	u_int8_t ether_dhost[6]; //目的以太地址
	u_int8_t ether_shost[6]; //源以太网地址
	u_int16_t ether_type;	 //以太网类型
};

/*定义ip地址格式*/
typedef u_int32_t in_addr_t;

struct ip_header
{
#ifdef WORKS_BIGENDIAN
	u_int8_t ip_version : 4,  //协议类型 version
		ip_header_length : 4; //首部长度 Length
#else
	u_int8_t ip_header_length : 4,
		ip_version : 4;
#endif
	u_int8_t ip_tos;					   //服务类型 type of service
	u_int16_t ip_length;				   //总长度 total Length
	u_int16_t ip_id;					   //标识 identifier
	u_int16_t flags : 3,				   //标志 flags
		ip_offset : 13;					   //位偏移 offset
	u_int8_t ip_ttl;					   //生存时间 Time To Live
	u_int8_t ip_protocol;				   //协议类型(TCP or UDP) protocol
	u_int16_t ip_checksum;				   //首部检验和 header checksum
	struct in_addr ip_source_address;	   //源IP source ip addr
	struct in_addr ip_destination_address; //目的IP destination ip addr
};

/*TCP首部的定义*/
struct tcp_header
{
	u_int16_t tcp_source_port; //源端口号

	u_int16_t tcp_destination_port; //目的端口号

	u_int32_t tcp_acknowledgement; //序号

	u_int32_t tcp_ack; //确认号字段
#ifdef WORDS_BIGENDIAN
	u_int8_t tcp_offset : 4,
		tcp_reserved : 4;
#else
	u_int8_t tcp_reserved : 4,
		tcp_offset : 4;
#endif
	u_int8_t tcp_flags;
	u_int16_t tcp_windows;		  //窗口字段
	u_int16_t tcp_checksum;		  //检验和
	u_int16_t tcp_urgent_pointer; //紧急指针字段
};

/*tcp数据包分析的函数定义 tcp_protocol_packet_callback*/
void tcp_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)
{
	struct tcp_header *tcp_protocol; //tcp协议变量

	u_char flags; //标记

	int header_length; //头长度

	u_short source_port; //源端口

	u_short destination_port; //目的端口

	u_short windows; //窗口大小

	u_short urgent_pointer; //紧急指针

	u_int sequence; //序列号

	u_int acknowledgement; //确认号

	u_int16_t checksum; //检验和

	tcp_protocol = (struct tcp_header *)(packet_content + 14 + 20); //获得tcp首部内容

	source_port = ntohs(tcp_protocol->tcp_source_port); //获得源端口号

	destination_port = ntohs(tcp_protocol->tcp_destination_port); //获得目的端口号

	header_length = tcp_protocol->tcp_offset * 4; //获得首部长度

	sequence = ntohl(tcp_protocol->tcp_acknowledgement); //获得序列号

	acknowledgement = ntohl(tcp_protocol->tcp_ack);
	windows = ntohs(tcp_protocol->tcp_windows);
	urgent_pointer = ntohs(tcp_protocol->tcp_urgent_pointer);
	flags = tcp_protocol->tcp_flags;
	checksum = ntohs(tcp_protocol->tcp_checksum);

	printf("---------------------------------------\n");
	printf("\nTransport layer (TCP protocol)\n");
	printf("Source port：\t\t%d\n", source_port);
	printf("Destination port：\t%d\n", destination_port);

	int min = (destination_port < source_port) ? destination_port : source_port;
	cout << "Application layer protocols：";
	switch (min)
	{
	case 80:
		printf("http");
		break;
	case 21:
		printf("ftp");
		break;
	case 23:
		printf("telnet");
		break;
	case 25:
		printf("smtp");
		break;
	case 110:
		printf("pop3");
		break;
	case 443:
		printf("https");
		break;
	default:
		printf("others");
		break;
	}
	cout << endl
		 << endl;
	printf("序列号：\t%u \n", sequence);
	printf("确认号：\t%u \n", acknowledgement);
	printf("首部长度：\t%d \n", header_length);
	printf("保留字段：\t%d \n", tcp_protocol->tcp_reserved);
	printf("控制位：");
	if (flags & 0x08)
		printf("\t推送 PSH");
	if (flags & 0x10)
		printf("\t确认 ACK");
	if (flags & 0x02)
		printf("\t同步 SYN");
	if (flags & 0x20)
		printf("\t紧急 URG");
	if (flags & 0x01)
		printf("\t终止 FIN");
	if (flags & 0x04)
		printf("\t【复位 RST】");

	printf("\n");
	printf("窗口大小 :\t%d \n", windows);
	printf("检验和 :\t%d\n", checksum);
	printf("紧急指针字段 :\t%d\n", urgent_pointer);
	printf("---------------------------------------\n");
}
/*数据包分析的函数定义 ethernet_protocol_packet_callback*/
void ip_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)
{
	struct ip_header *ip_protocol; //ip协议变量

	ip_protocol = (struct ip_header *)(packet_content + 14); //获得ip数据包的内容去掉以太头部

	cout << "IP版本:\t\t"
		 << "IPv" << (int)(ip_protocol->ip_version) << endl;						 //获取头部长度字段
	cout << "IP头部长度:\t" << ((ip_protocol->ip_header_length & 0x0f) * 4) << endl; //获取头部长度字段
	cout << "服务类型:\tPriority" << (ip_protocol->ip_tos >> 5)
		 << ", Service" << ((ip_protocol->ip_length >> 1) & 0x0f) << endl; //获取标志位
	cout << "总长度:\t\t" << ntohs(ip_protocol->ip_length) << endl;		   //获取总长度字段
	cout << "标识:\t\t" << ntohs(ip_protocol->ip_id) << endl;			   //获取标识字段
	cout << "分段标志:\t" << ((ip_protocol->flags >> 15) & 0x01)
		 << ",DF= " << ((ip_protocol->flags >> 14) & 0x01)
		 << ",Mf=" << ((ip_protocol->flags >> 13) & 0x01) << endl;					   //获得标志字段
	cout << "分段偏移值:\t" << (ntohs(ip_protocol->ip_offset) & 0x1fff) << endl;	   //获取分段偏移字段
	cout << "生存时间:\t" << (int)ip_protocol->ip_ttl << endl;						   //获取生存时间字段
	cout << "协议:\t\t" << (int)ip_protocol->ip_protocol << endl;					   //获取协议字段
	cout << "头部校验和:\t" << ntohs(ip_protocol->ip_checksum) << endl;				   //获取头校验和字段
	cout << "源IP地址:\t" << inet_ntoa(ip_protocol->ip_source_address) << endl;		   //获取源IP地址字段
	cout << "目的IP地址:\t" << inet_ntoa(ip_protocol->ip_destination_address) << endl; //获取目的IP地址字段

	cout << "\nThe transport layer protocol:";
	switch (ip_protocol->ip_protocol)
	{
	case 6:
		cout << "TCP" << endl;
		tcp_protocol_packet_callback(argument, packet_header, packet_content);
		break; //协议类型是6代表TCP
	case 17:
		cout << "UDP" << endl;
		break; //17代表UDP
	case 1:
		cout << "ICMP" << endl;
		break; //1代表ICMP
	case 2:
		cout << "IGMP" << endl;
		break; //2代表IGMP
	default:
		break;
	}
	printf("---------------------------------------\n");
}

void ethernet_protocol_packet_callback(u_char *argument, const struct pcap_pkthdr *packet_header, const u_char *packet_content)
{
	u_short ethernet_type; //以太网协议类型

	struct ethernet_header *ethernet_protocol; //以太网协议变量

	u_char *mac_string;

	static int packet_number = 1;
	cout << endl
		 << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=" << endl;
	printf("\tThe Num %d IP packet is captured.\n", packet_number);
	printf("\nLink layer (Ethernet protocol)\n");
	ethernet_protocol = (struct ethernet_header *)packet_content; //获得以太网协议数据内容

	cout << "The Ethernet type is:";
	ethernet_type = ntohs(ethernet_protocol->ether_type); //获得以太网类型
	printf("%04x\n", ethernet_type);

	switch (ethernet_type) //判断以太网类型的值
	{
	case 0x0800:
		cout << "The network layer: IPv4 protocol\n"
			 << endl;
		break;
	case 0x0806:
		cout << "The network layer: ARP protocol\n"
			 << endl;
		break;
	case 0x8035:
		cout << "The network layer: RARP protocol\n"
			 << endl;
		break;
	default:
		break;
	}

	printf("Mac源地址:\t");
	mac_string = ethernet_protocol->ether_shost; //获得Mac源地址
	printf("%02x:%02x:%02x:%02x:%02x:%02x:\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));

	printf("Mac目的地址:\t");
	mac_string = ethernet_protocol->ether_dhost; //获得Mac目的地址
	printf("%02x:%02x:%02x:%02x:%02x:%02x:\n", *mac_string, *(mac_string + 1), *(mac_string + 2), *(mac_string + 3), *(mac_string + 4), *(mac_string + 5));

	switch (ethernet_type)
	{
	case 0x0800:
		//如果上层是IPv4ip协议,就调用分析ip协议的函数对ip包进行贩治
		ip_protocol_packet_callback(argument, packet_header, packet_content);
		break;
	default:
		break;
	}
	packet_number++;
}

int main(int argc, char *argv[])
{
	if (argc != 6) //程序名也算一个参数 ,  | tee logfile.txt(3个参数)
	{
		printf("Error,the number of command line parameters is not correct, please check and re-run the program.\n");
		//return -1;//参数不正确时,不强行结束程序,提示用户
	}

	cout << "Parsing IP packets......" << endl
		 << endl;
	pcap_if_t *alldevs;
	pcap_if_t *d;
	int inum = 0;
	int i = 0;
	pcap_t *adhandle;
	char errbuf[PCAP_ERRBUF_SIZE];

	//获得网卡的列表
	if (pcap_findalldevs(&alldevs, errbuf) == -1)
	{
		fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
		exit(1);
	}

	//打印网卡信息
	for (d = alldevs; d; d = d->next)
	{
		cout << ++i << ".  " << d->name;
		if (d->description)
			cout << "\t" << d->description << endl;
		else
			cout << "\nNo NIC description available\n"
				 << endl;
	}

	if (i == 0)
	{
		cout << "\nNo interface found! Make sure LibPcap is installed!" << endl;
		return -1;
	}

	inum = atoi(argv[1]);
	if (inum < 1 || inum > i) //判断号的合法性
	{
		cout << "\nPlease enter the correct NIC number.\n"
			 << endl;
		pcap_freealldevs(alldevs); //释放设备列表
		return -1;
	}

	//找到要选择的网卡结构
	for (d = alldevs, i = 0; i < inum - 1; d = d->next, i++)
		;

	//打开选择的网卡
	if ((adhandle = pcap_open_live(d->name,
								   65536, //最大值65536,表示允许整个包在所有mac电脑上被捕获
								   1,	  // 混杂模式
										  /*混杂模式是指一台主机能够接受所有经过它的数据流，不论这个数据流的目的地址是不是它，它都会接受这个数据包。
也就是说，混杂模式下，网卡会把所有的发往它的包全部都接收。在这种情况下，可以接收同一集线器局域网的所有数据。*/
								   1000,  // 读超时为1秒
								   errbuf // error buffer
								   )) == NULL)
	{
		fprintf(stderr, "\nCouldn't open the adapter because it wasn't supported by LibPcap.\n");
		pcap_freealldevs(alldevs); //释放设备列表
		return -1;
	}
	cout << "\nListening to  " << d->description << "......" << endl;
	pcap_freealldevs(alldevs); // 现在我们不再需要设备列表释放它

	int cnt = -1;
	cnt = atoi(argv[2]);

	/* 开始以回调的方式捕获包
  函数名称：int pcap_loop(pcap_t * p,int cnt, pcap_handler callback, uchar * user);
  函数功能：捕获数据包,不会响应pcap_open_live()函数设置的超时时间
  */
	pcap_loop(adhandle, cnt, ethernet_protocol_packet_callback, NULL);
	cout << "\nParsing IP Packet Ended\n";

	return 0;
}