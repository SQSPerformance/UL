Action()
{

	web_url("prestashop", 
		"URL=http://msdn-dev-build2.pd.group.intl:8080/prestashop/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=themes/classic/assets/css/a35546eef3ea0de0d4735f23b0a0873b.eot", ENDITEM, 
		"Url=themes/classic/assets/css/e487b7cb072550896dde6821d24de2be.eot", ENDITEM, 
		"Url=themes/classic/assets/css/0ea04502930623aa3de110aac9f9e4fd.eot", ENDITEM, 
		"Url=themes/classic/assets/css/da061416028fc9a66fbc0b80d33d6e6f.eot", ENDITEM, 
		"Url=themes/classic/assets/css/7ae9b8ba7886341831bf7c85a0da40d0.eot", ENDITEM, 
		"Url=themes/classic/assets/css/012cf6a10129e2275d79d6adac7f3b02.woff", ENDITEM, 
		"Url=themes/classic/assets/css/ea07932c5245dd421e3d05f579098bc2.eot", ENDITEM, 
		LAST);

	web_link("&#xE7FF; Sign in", 
		"Text=&#xE7FF; Sign in", 
		"Snapshot=t2.inf", 
		LAST);

	web_submit_form("login", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=email", "Value=ptest@sqs.com", ENDITEM, 
		"Name=password", "Value=111222", ENDITEM, 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_cookie("MC1=GUID=8dff168c74d4d449b7e769f60049bcbe&HASH=8c16&LV=201701&V=4&LU=1483437594145; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("A=I&I=AxUFAAAAAAAECAAACT5wi6tCVqw6I9uEwFTzdg!!&V=4; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("MSFPC=ID=8dff168c74d4d449b7e769f60049bcbe&CS=3&LV=201701&V=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("MUID=2C4886F33B2268320E8C8CFF3F226BD5; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20170103; DOMAIN=iecvlist.microsoft.com");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("prestashop_2", 
		"URL=http://msdn-dev-build2.pd.group.intl:8080/prestashop/?mylogout=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://msdn-dev-build2.pd.group.intl:8080/prestashop/my-account", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	return 0;
}