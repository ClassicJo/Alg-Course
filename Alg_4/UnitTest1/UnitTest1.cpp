#include "pch.h"
#include "CppUnitTest.h"
#include "..\Alg_4\FordFulkerson.h"
#include "..\Alg_4\FordFulkerson.cpp"

#define TEST_CASE_DIRECTORY GetDirectoryName(__FILE__)
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Fordtest
{
	TEST_CLASS(test)
	{
		string GetDirectoryName(string path) 
		{
			const size_t last_slash_idx = path.rfind('\\');
			if (std::string::npos != last_slash_idx)
			{
				return path.substr(0, last_slash_idx + 1);
			}
			return "";
		}
	public:

		TEST_METHOD(empty_file)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_empty.txt";
			FordFulkerson test;
			int result;
			try
			{
				test.readList(fileName);
				result = test.MaxFlow();
			}
			catch (out_of_range e)
			{
				Assert::AreEqual(e.what(), "Graph is empty");
			}
		}
		TEST_METHOD(graph_test1)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_1.txt";
			FordFulkerson test;
			int result;
			test.readList(fileName);
			result = test.MaxFlow();
			Assert::AreEqual(result, 30);
		}
		TEST_METHOD(graph_test2)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_2.txt";
			FordFulkerson test;
			int result;
			test.readList(fileName);
			result = test.MaxFlow();
			Assert::AreEqual(result, 10);
		}
		TEST_METHOD(graph_test3)
		{
			string fileName = std::string(TEST_CASE_DIRECTORY) + "test_3.txt";
			FordFulkerson test;
			int result;
			test.readList(fileName);
			result = test.MaxFlow();
			Assert::AreEqual(result, 20);
		}
	};
}
