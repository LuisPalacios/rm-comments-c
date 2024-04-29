#include <iostream>
#include <string>
using namespace std;

string removeComments()
{
	string res;
	bool s_cmt = false;
	bool m_cmt = false;

	char c;
	while (cin.get(c)) {
		// If single line comment flag is on, then check for end of it
		if (s_cmt && c == '\n')
			s_cmt = false;

		// If multiple line comment is on, then check for end of it
		else if (m_cmt && c == '*' && cin.peek() == '/')
			m_cmt = false, cin.get();

		// If this character is in a comment, ignore it
		else if (s_cmt || m_cmt)
			continue;

		// Check for beginning of comments and set the appropriate flags
		else if (c == '/' && cin.peek() == '/')
			s_cmt = true, cin.get();
		else if (c == '/' && cin.peek() == '*')
			m_cmt = true, cin.get();

		// If current character is a non-comment character, append it to res
		else
			res += c;
	}
	return res;
}

int main()
{
	//cout << "Enter the program (Ctrl+D to end input):\n";

	string prgm = removeComments();
	//cout << "\nProgram without comments:\n";
	cout << prgm;

	return 0;
}
