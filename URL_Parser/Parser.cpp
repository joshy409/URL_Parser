#include <iostream>
#include <string>
using namespace std;

bool validURL(string scheme, string netloc);
string getFragment(string& url);
string getQuery(string& url);
string getScheme(string& url);
string getNetloc(string& url);

int main()
{
	string url;
	cout << "Please enter a URL (type 'end' to end): ";
	getline(cin, url);

	while (url != "end")
	{
		cout << "\nThe URL is: " << url << endl;
		string fragment = getFragment(url);
		string query = getQuery(url);
		string scheme = getScheme(url);
		string netloc = getNetloc(url);

	if (validURL(scheme, netloc))
	{
		cout << "<scheme> = " << scheme << endl;
		cout << "<netloc> = " << netloc << endl;
		cout << "<path> = " << url << endl;
		cout << "<query> = " << query << endl;
		cout << "<fragment> = " << fragment << endl;
		cout << "\nPlease enter a URL(type 'end' to end) : ";
		getline(cin, url);
	}
	else
	{
		cout << "\nInvalid URL" << endl;
		cout << "\nPlease enter a valid URL (type 'end' to end): ";
		getline(cin, url);
	}
	}
}


// checks if scheme or netloc is empty
bool validURL(string scheme, string netloc)
{
	if (scheme.size() == 0 || netloc.size() == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// searches for "#" and gets the fragment and chops it off from url
string getFragment(string& url)
{
	string fragment = "";
	int fragmentindex = url.find("#");
	if (fragmentindex == -1)
	{
		return fragment;
	}
	else
	{
		fragment = url.substr(fragmentindex + 1);
		url.erase(fragmentindex);
		return fragment;
	}
}

//searches for "?" and gets the query and chops it off from url
string getQuery(string& url)
{
	string query = "";
	int queryindex = url.find("?");

	if (queryindex == -1)
	{
		return query;
	}
	else
	{
		query = url.substr(queryindex + 1);
		url.erase(queryindex);
		return query;
	}
}

// searches for ":" and gets the scheme and chops it off from url
string getScheme(string& url)
{
	string scheme = "";
	int schemeindex = url.find(":");
	if (schemeindex == -1)
	{
		return scheme;
	}
	else
	{
		scheme = url.substr(0, schemeindex);
		url = url.substr(schemeindex + 1);
		return scheme;
	}
}

//searches for "//" to get netloc and "/" to get path. chops off the netloc and anything left on url is path
string getNetloc(string& url)
{
	string netloc = "";
	int netlocindex = url.find("//");
	if (netlocindex == -1)
	{
		return netloc;
	}
	else
	{
		url = url.substr(netlocindex + 2);
		int pathindex = url.find_first_of("/");
		if ( pathindex == -1)
		{
			netloc = url;
			url = "";
		}
		else
		{
			netloc = url.substr(0, pathindex);
			url = url.substr(pathindex + 1);
		}
		return netloc;
	}
}
