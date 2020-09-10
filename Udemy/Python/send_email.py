import smtplib
import getpass

smtp_object = smtplib.SMTP('smtp.gmail.com', 587)

# Identify yourself to an ESMTP server using EHLO
smtp_object.ehlo()

# Put the SMTP connection in TLS mode.
# All SMTP commands that follow will be encrypted.
# You should then call ehlo() again.
smtp_object.starttls()
smtp_object.ehlo()

# Login into your account
email = input("Email: ")

# getpass make your passwd invisible when inputing
passwd = getpass.getpass("Password: ")
smtp_object.login(email, passwd)

# Send email
from_addr = input("Email(send): ")
to_addr = input("Email(recv): ")

subject = input("Enter subject: ")
message = input("Enter message you want to write: ")
msg = "Subject: " + subject + '\n' + message

smtp_object.sendmail(from_addr, to_addr, msg)

# Quit
smtp_object.quit()
