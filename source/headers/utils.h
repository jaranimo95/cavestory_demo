#ifndef utils_h
#define utils_h

class Utils {
public:
	
	//unsigned int split
	//split a string <txt> everywhere a certain character <ch> is found
	//store the resulting substrings in a vector <strs>
	//returns the size of the vector
	// ex. std::string "25,46,3,64" -> split by ch ',' -> store in &strs -> return # of tokens
	static unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch) {
		int pos = (int)txt.find(ch);
		int initialPos = 0;
		strs.clear();
		
		//While we have found an instance of ch
		while(pos != std::string::npos) {
			strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
			initialPos = pos + 1;
			
			pos = (int)txt.find(ch, initialPos);
		}
		// Add the last one
		strs.push_back(txt.substr(initialPos, std::min<int>(pos, (int)txt.size() - (initialPos + 1))));
		
		return (int)strs.size();
	}
	
};

#endif /* utils_h */
