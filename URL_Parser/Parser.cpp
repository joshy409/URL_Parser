#include <iostream>
#include <string>
using namespace std;

bool validURL(string url);
string getFragment(string& url);
string getQuery(string& url);
string getScheme(string& url);
string getNetloc(string& url);

int main()
{
	string url;
	cout << "please enter a url (type 'end' to end): ";
	getline(cin, url);

	while (url != "end")
	{
		if (validURL(url))
		{
			cout << "\nthe url is: " << url << endl;
			string fragment = getFragment(url);
			string query = getQuery(url);
			string scheme = getScheme(url);
			string netloc = getNetloc(url);
			cout << "<scheme> = " << scheme << endl;
			cout << "<netloc> = " << netloc<< endl;
			cout << "<path> = " << url << endl;
			cout << "<query> = " << query << endl;
			cout << "<fragment> = " << fragment << endl;
			cout << "\nplease enter a url: ";
			getline(cin, url);
		}
		else
		{
			cout << "\ninvalid url" << endl;
			cout << "\nplease enter a valid url: ";
			getline(cin, url);
		}
	}
		
}

// checks if the url valid
bool validURL(string url)
{
	int i = url.find("://");
	if (i == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// gets fragment from url and chop off  "#" and the fragment from url
string getFragment(string& url)
{
	string fragment;
	int i = url.find("#");
	if (i == -1)
	{
		fragment = "";
	}
	else 
	{
		fragment = url.substr(i + 1);
		url = url.erase(i);
	}
	return fragment;
}

//gets query from url and chop off "?" and the query from url
string getQuery(string& url)
{
	string query;
	int i = url.find("?");
	
	if (i == -1)
	{
		query = "";
	}
	else
	{
		query = url.substr(i + 1);
		url = url.erase(i);
	}
	return query;
}

// gets scheme from url and chops off "://" and the scheme from url
string getScheme(string& url)
{
	string scheme;
	int i = url.find(":");
	if (i == -1)
	{
		scheme = "";
	}
	else
	{
		scheme = url.substr(0, i);
		url = url.substr(i + 3);
	}
	return scheme;
}
 
//get netloc from the url and chop off "/" and netloc from url
string getNetloc(string& url)
{
	string netloc;
	int i = url.find_first_of("/");
	if (i == -1)
	{
		netloc = url.substr(0, i);
		url = "";
	}
	else
	{
		netloc = url.substr(0, i);
		url = url.substr(i + 1);
	}
	return netloc;
}