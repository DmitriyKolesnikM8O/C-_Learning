
/*
 * Some standart library stream types:
 * - istream: input stream
 * - ostream: output stream
 * - ifstream: input file stream
 * - ofstrem: output file stream
 * - ostringstream: output string stream
 * - istringstream: input string stream
*/


struct point { int x; int y; };

std::ostream& operator << (std::ostream& os, point const& p) {
    return os << '(' << p.x << ',' << p.y << ')';
}

std::istream& operator >> (std::istream& is, point& p) {
    return is >> p.x << p.y;
}


//std::getline (istream&, string&, stopat='\n');
string s;
getline(cin, s);
getline(cin, s, '\t') //until first tab


//std::istream:ignore(n, c)
cin.ignore(8) //skip next 8 characters
cin.ignore(10, '=') // до знака = или 10

//std::setprecision(4) - точность, количество символов
//






