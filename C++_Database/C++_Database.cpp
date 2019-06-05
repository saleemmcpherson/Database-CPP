#include "pch.h"
#include <iostream>
#using <mscorlib.dll>
#using <System.Data.dll>
#using <System.dll>
#include <atldbcli.h>
#include <atldbsch.h>

using namespace std;
using namespace System;
using namespace System::Data::OleDb;

int main(void)
{
	String^ sqlstr = "SELECT * FROM [Categories]";

	OleDbConnection^ conn = nullptr;
	OleDbCommand^ cmd = nullptr;

	try
	{
		conn = gcnew OleDbConnection("PROVIDER=Microsoft.Jet.OLEDB.4.0;Data Source=C:Northwind.MDB");
		conn->Open();
		cmd = gcnew OleDbCommand(sqlstr, conn);

		OleDbDataReader^ reader = cmd->ExecuteReader(System::Data::CommandBehavior::CloseConnection);
		String^ Sep = gcnew String('*', 60);

		while (reader->Read())
		{
			Console::WriteLine("CategoryID: " + reader["CategoryID"]);
			Console::WriteLine("CategoryName: " + reader["CategoryName"] + "\t");
			Console::WriteLine("Description: " + reader["Description"]);
			Console::WriteLine(Sep);
		}
	}
	catch (Exception^ ex)
	{
		Console::WriteLine(ex->ToString());
	}
	Console::ReadLine();
	return 0;
}
