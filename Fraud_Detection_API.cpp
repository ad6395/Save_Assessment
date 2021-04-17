

#include <mysql.h>
#include <iostream>

using namespace std;
int qstate;



class Save {

public:

	string conn;

	void connection() {

		MYSQL* conn;
		MYSQL_ROW row;
		MYSQL_RES* res;
		conn = mysql_init(0);

		conn = mysql_real_connect(conn, "localhost", "root", "Abhishek6395@", "save", 3306, NULL, 0);

	
	}

	

	int Abnormal_Transaction()
	{

		MYSQL* conn;
		MYSQL_ROW row;
		MYSQL_RES* res;
		conn = mysql_init(0);

		conn = mysql_real_connect(conn, "localhost", "root", "Abhishek6395@", "save", 3306, NULL, 0);

		if (conn) {
			puts("Successful connection to database! API for Abnormal Transaction!");

			string query1 = "Select * from account_info a join (select tr.account_number, tr.transaction_amount, tr.transaction_number, tr.merchant_number, tr.merchant_description, x.avg_amount from transactions tr join (select t.account_number, avg(t.transaction_amount) as avg_amount, t.merchant_number, t.merchant_description from transactions t join account_info ai on t.account_number = ai.account_number group by t.account_number, t.merchant_number) x on x.account_number = tr.account_number where x.merchant_number = tr.merchant_number and x.avg_amount / tr.transaction_amount < .30) m on a.account_number = m.account_number";
			const char* q = query1.c_str();
			qstate = mysql_query(conn, q);
			if (!qstate)
			{
				res = mysql_store_result(conn);
				while (row = mysql_fetch_row(res))
				{
					printf("FirstName: %s, LastName:  %s, Account Number:  %s, Transaction Number:  %s, Merchant:  %s, Transaction Amount:  %s\n\n", row[1], row[0], row[11], row[14], row[16], row[13]);
				}
			}
			else
			{
				cout << "Query failed: " << mysql_error(conn) << endl;
			}
	
		}
		else {
			puts("Connection to database has failed!");
		}

		return 0;
	}

	int Suspicious_Location() 
	{

		MYSQL* conn;
		MYSQL_ROW row;
		MYSQL_RES* res;
		conn = mysql_init(0);

		conn = mysql_real_connect(conn, "localhost", "root", "Abhishek6395@", "save", 3306, NULL, 0);
		if (conn) {
			puts("Successful connection to database! API for Suspicious Location!");
			string query2 = "select * from transactions tr join account_info ai on tr.account_number = ai.account_number where tr.transaction_state!= ai.state;";
			const char* q2 = query2.c_str();
			qstate = mysql_query(conn, q2);
			if (!qstate)
			{
				res = mysql_store_result(conn);
				while (row = mysql_fetch_row(res))
				{
					printf(" First Name: %s, Last_Name: %s, Account_Number: %s, Transaction_Number: %s, Expected Transaction State: %s, Actual Transaction State: %s\n\n", row[10], row[9], row[0], row[7], row[14], row[8]);
				}
			}
			else
			{
				cout << "Query failed: " << mysql_error(conn) << endl;
			}
		}


		else {
			puts("Connection to database has failed!");
		}

		return 0;

	}
};



	int main() {

		Save obj1;

		obj1.Abnormal_Transaction();

		obj1.Suspicious_Location();
	}
