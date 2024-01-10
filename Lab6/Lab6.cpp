#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Book
{
	char* author;
	char* title; // string also accepted
	int pages_nr;
	int* page_wordcount;
	bool online;

public:
	char* getauthor() { return this->author; }
	char* gettitle() { return this->title; }
	int getpages_nr() { return this->pages_nr; }
	int* getpage_wordcount() { return this->page_wordcount; }
	bool getonline() { return this->online; }

	void setauthor(char* author)
	{
		if (this->author != NULL)
			delete[] this->author;
		this->author = new char[strlen(author) + 1];
		strcpy(this->author, author);
	}
	void settitle(char* title)
	{
		if (this->title != NULL)
			delete[] this->title;
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
	}
	void setpages_nr(int pages_nr) { this->pages_nr = pages_nr; }
	void setpage_wordcount(int* page_wordcount)
	{
		if (this->page_wordcount != NULL)
			delete[] this->page_wordcount;
		this->page_wordcount = new int[this->pages_nr];
		for (int i = 0; i < this->pages_nr; i++)
			this->page_wordcount[i] = page_wordcount[i];
	}
	void setonline(bool online) { this->online = online; }
	Book(char* author, char* title, int pages_nr, int* page_wordcount, bool online)
	{
		if (this->author != NULL)
			delete[] this->author;
		this->author = new char[strlen(author) + 1];
		strcpy(this->author, author);
		if (this->title != NULL)
			delete[] this->title;
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		if (this->page_wordcount != NULL)
			delete[] this->page_wordcount;
		this->page_wordcount = new int[pages_nr];
		for (int i = 0; i < pages_nr; i++)
			this->page_wordcount[i] = page_wordcount[i];
		this->pages_nr = pages_nr;
		this->online = online;
	}
	Book(const Book& b)
	{
		if (this->author != NULL)
			delete[] this->author;
		this->author = new char[strlen(b.author) + 1];
		strcpy(this->author, b.author);
		if (this->title != NULL)
			delete[] this->title;
		this->title = new char[strlen(b.title) + 1];
		strcpy(this->title, b.title);
		this->pages_nr = b.pages_nr;
		if (this->page_wordcount != NULL)
			delete[] this->page_wordcount;
		this->page_wordcount = new int[pages_nr];
		for (int i = 0; i < b.pages_nr; i++)
			this->page_wordcount[i] = b.page_wordcount[i];
		this->online = b.online;
	}
	~Book()
	{
		if (this->author != NULL)
			delete[] this->author;
		if (this->title != NULL)
			delete[] this->title;
		if (this->page_wordcount != NULL)
			delete[] this->page_wordcount;
	}
};

int main() {
	int page_wordcount[10] = { 100, 23, 48, 28, 57, 55, 147, 52, 62, 52 };
	char author[] = "Andrici Sabina";
	char title[] = "o zi minunata";
	Book b(author, title, 10, page_wordcount, true);
	Book b1 = b;
}
