Action()
{
	
	web_set_sockets_option("SSL_VERSION", "2&3");
		
	lr_start_transaction("MVP_BP04_01_LaunchBrowser");

		web_url("prestashop", 
		"URL=http://msdn-dev-build2.pd.group.intl:8080/prestashop/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("MVP_BP04_01_LaunchBrowser", LR_AUTO);
	
	lr_think_time(9);
	
	web_reg_find("Text=Email", "SaveCount=Signin_Count", LAST);

	lr_start_transaction("MVP_BP04_02_ClickSignIn");

	web_link("&#xE7FF; Sign in", 
		"Text=&#xE7FF; Sign in", 
		"Snapshot=t2.inf", 
		LAST);
	
	if (atoi(lr_eval_string("{Signin_Count}")) == 0)
	{
        lr_end_transaction("MVP_BP04_02_ClickSignIn",LR_FAIL);
		lr_error_message("Sign in not displayed");
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE , LR_FAIL);
	}

	else
	{
		lr_end_transaction("MVP_BP04_02_ClickSignIn",LR_PASS); 
	}
	
	web_reg_find("Text=P Test", "SaveCount=Login_Count", LAST);

	lr_start_transaction("MVP_BP04_03_EnterDetails");
	
	web_submit_form("login",
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=email", "Value=ptest@sqs.com", ENDITEM, 
		"Name=password", "Value=111222", ENDITEM, 
		LAST);
	
	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	if (atoi(lr_eval_string("{Login_Count}")) == 0)
	{
        lr_end_transaction("MVP_BP04_03_EnterDetails",LR_FAIL);
		lr_error_message("Unable to login");
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE , LR_FAIL);
	}

	else
	{
		lr_end_transaction("MVP_BP04_03_EnterDetails",LR_PASS); 
	}
	
	web_reg_find("Text=Sign in", "SaveCount=Logout_Count", LAST);
	
	lr_start_transaction("MVP_BP04_04_SignOut");

	web_url("prestashop_2", 
		"URL=http://msdn-dev-build2.pd.group.intl:8080/prestashop/?mylogout=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://msdn-dev-build2.pd.group.intl:8080/prestashop/my-account", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);
	
	if (atoi(lr_eval_string("{Logout_Count}")) == 0)
	{
        lr_end_transaction("MVP_BP04_04_SignOut",LR_FAIL);
		lr_error_message("Signout unsuccessful");
		lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE , LR_FAIL);
	}

	else
	{
		lr_end_transaction("MVP_BP04_04_SignOut",LR_PASS); 
	}

	return 0;
}