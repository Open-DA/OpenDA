import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.net.Socket;
import java.text.DateFormat;
import java.util.Base64;
import java.util.Date;
import java.util.Locale;

public class AuthSender {
	public static void main(String[] args) throws Exception {
		Date dDate = new Date();
		DateFormat dFormat = DateFormat.getDateTimeInstance(DateFormat.FULL,DateFormat.FULL,
				Locale.US);
		String command = null;

		/** 与邮件服务器建立TCP连接. */
		// TODO: 1.在""中填入我们的smtp服务器和正确端口，清华邮件服务器mails.tsinghua.edu.cn，端口是25
		// e.g. Socket socket = new Socket("mails.163.com",25);
		Socket socket = new Socket("mails.tsinghua.edu.cn", 25);

		/** 创建BufferedReader每次读入一行信息. */
		InputStream is = socket.getInputStream();
		InputStreamReader isr = new InputStreamReader(is);
		BufferedReader br = new BufferedReader(isr);

		/** 读入系统的欢迎信息. */
		String response = br.readLine();
		System.out.println(response);
		// TODO: 2.把code改为合适的代码
		int code = 220;	//把-1改为合适的代码
		if (!response.startsWith(Integer.toString(code))) {
			throw new Exception(code + " reply not received from server.");
		}

		/** 取得socket输出流的引用. */
		OutputStream os = socket.getOutputStream();

		/** 发送 HELO 命令并取得服务器响应. 
		 *	填入所需的命命, 在以下的"\r\n"前写入所需的命令 
		 *	e.g.	command = "Helo x\r\n";
		 *	其中\r\n为回车符,每个命今都必需以它们结尾. */
		// TODO: 3.填入命令
		command = "HELO TsinghuaMail\r\n";
		System.out.print(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		// TODO: 4.把code改为合适的代码
		code = 250; //把-1改为合适的代码
		if (!response.startsWith(Integer.toString(code))) {
			throw new Exception(code + " reply not received from server.");
		}
		
		
		
		/**
		 *发送Auth Login请求验证 
		 *需要发送BASE64编码的用户名和密码
		 */
		// TODO: 5.补全命令
		command = "Auth Login\r\n";
		System.out.print(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		// 服务器响应334时继续输入用户名和密码
		// TODO: 6.补全命令
		code = 334; //把-1改为合适的代码
		if (!response.startsWith(Integer.toString(code))) {
			throw new Exception(code + " reply not received from server.");
		}
		//发送用户名和密码
		//TODO: 7.将x@x.x修改为合适的地址
		String username = "****@mails.tsinghua.edu.cn";
		Base64.Encoder encoder = Base64.getEncoder();
		//BASE64编码
		String username_encoded = encoder.encodeToString(username.getBytes()) + "\r\n";
		os.write(username_encoded.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		// 服务器响应334时继续输入密码
		// TODO: 7.补全命令
		code = 334; //把-1改为合适的代码
		if (!response.startsWith(Integer.toString(code))) {
			throw new Exception(code + " reply not received from server.");
		} 
		String password = "****";
		String password_encoded = encoder.encodeToString(password.getBytes()) + "\r\n";
		os.write(password_encoded.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		//响应开头为235表示验证成功
		// TODO: 8.补全命令
		code = 235; //把-1改为合适的代码
		if (!response.startsWith(Integer.toString(code))) {
			throw new Exception(code + " reply not received from server.");
		} 
		 
		
		

		/** 发送 MAIL FROM 命令. */
		// TODO: 9.将x@x.x改为合适的地址
		command = "MAIL FROM:<****@mails.tsinghua.edu.cn>\r\n";
		System.out.print(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		// TODO: 10.把code改为合适的代码
		code = 250; //把-1改为合适的代码
		if (!response.startsWith(Integer.toString(code))) {
			throw new Exception(code + " reply not received from server.");
		}

		/** 发送 RCPT TO 命令. */
		// TODO: 11.将x@x.x改为合适的地址
		command = "RCPT TO:<****@126.com>\r\n";
		System.out.print(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		// TODO: 12.把code改为合适的代码
		 code = 250; //把-1改为合适的代码
		if (!response.startsWith(Integer.toString(code))) {
			throw new Exception(code + " reply not received from server.");
		}

		/** 发送 DATA 命令. */
		// TODO: 13.填入命令
		command = "DATA\r\n";
		System.out.print(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		// TODO: 14.把code改为合适的代码
		 code = 354; //把-1改为合适的代码
		if (!response.startsWith(Integer.toString(code))) {
			throw new Exception(code + " reply not received from server.");
		}

		/** 自动写入当前的日期 */
		String date = "DATE: " + dFormat.format(dDate) + "\r\n";
		System.out.print(date);
		os.write(date.getBytes("US-ASCII"));
		String str = "";
		// TODO: 15.把"x@x.x"改为邮件中显示的发件人地址
		str = "From:" + "****@mails.tsinghua.edu.cn" + "\r\n";
		System.out.print(str);
		os.write(str.getBytes("US-ASCII"));
		// TODO: 16.把"x@x.x"改为邮件中显示的收件人地址
		str = "To:" + "****@126.com" + "\r\n";
		System.out.print(str);
		os.write(str.getBytes("US-ASCII"));

		/** 发送邮件內容. */
		// TODO: 17.在"x"中填入Subject内容.
		str = "SUBJECT:" + "Admission" + "\r\n\r\n";
		System.out.print(str);
		os.write(str.getBytes("UTF-8"));
		// TODO: 18.在"x"中填入邮件正文内容.
		str = "Congratulations on your admission to Jialidun Univ!" + "\r\n";
		System.out.print(str);
		os.write(str.getBytes("UTF-8"));

		/** 以.作为邮件内容的结束符 */
		str = ".\r\n";
		System.out.print(str);
		os.write(str.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
		// TODO: 19.把code改为合适的代码
		 code = 250; //把-1改为合适的代码
		if (!response.startsWith(Integer.toString(code))) {
			throw new Exception(code + " reply not received from server.");
		}

		/** 发送 QUIT 命令. */
		//TODO:	20.填入命令
		command = "QUIT\r\n";
		System.out.print(command);
		os.write(command.getBytes("US-ASCII"));
		response = br.readLine();
		System.out.println(response);
	}
}
