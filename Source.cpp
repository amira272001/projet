#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
double cosineSimilarity(vector<int> v1, vector<int> v2) {
	const double invalid = 2.0;
	if (v1.size() != v2.size()) {
		return invalid;
	}

	double A_dot_B = 0.0, A_dot_A = 0.0, B_dot_B = 0.0;
	for (int i = 0; i < v1.size(); ++i) {
		A_dot_B += v1[i] * v2[i];
		A_dot_A += v1[i] * v1[i];
		B_dot_B += v2[i] * v2[i];
	}
	return A_dot_A && B_dot_B ?
		A_dot_B / sqrt(A_dot_A) / sqrt(B_dot_B) :
		invalid;
}


int main() {

	string a, b;
	vector <int> v1(1000);
	vector <int> v2(1000);


	cout << "donner deux fichiers txt :";
	cin >> a >> b;
	std::ifstream inFile1;
	std::ifstream inFile2;
	inFile1.open(a);
	inFile2.open(b);

// file1 to string
	std::stringstream strStream;
	strStream << inFile1.rdbuf(); //read the file
	std::string str1 = strStream.str(); //str holds the content of the file
	           //cout << str1 << endl;
// file2 to string
	std::stringstream strStream2;
	strStream2 << inFile2.rdbuf(); //read the file
	std::string str2 = strStream2.str(); //str holds the content of the file
	//cout << str2;
//token for file1
	string word;
	vector <string> tokens;
	stringstream check1(str1);
	string intermediate;
	while (getline(check1, intermediate, ' '))
	{
		tokens.push_back(intermediate);
	}
	//for (int i = 0; i < tokens.size(); i++) {
		 //cout << tokens[i];
	 //}
 //token for file2
	string word2;
	vector <string> tokens2;
	stringstream check2(str2);
	string intermediate2;
	while (getline(check2, intermediate2, ' ')){
		tokens2.push_back(intermediate2);
};
    // for (int i = 0; i < tokens2.size(); i++) {
		//cout << tokens2[i];
	//}; 
//remplir v2
	int k; k = 0;
	for (int i = 0; i < v1.size(); i++) {
		 v2[i]=0;
	}; 
	for (int j = 0; j < tokens2.size(); j++)
	{   
		word = tokens2[j]; 
		for (int i = 0; i < tokens2.size(); i++) {
			if (tokens2[i] == word)
			{
				tokens2[i] = ' ';
				v2[k] = v2[k] + 1;
			}
		} k = k + 1;
	} 
	for (int j = 0; j < tokens.size(); j++)
	{
		word = tokens[j];
		for (int i = 0; i < tokens2.size(); i++) {
			if (tokens2[i] == word)
			{
				tokens2[i] = ' ';
				v2[k] = v2[k] + 1;
			}
		} k = k + 1;
	}

// remplir v1
	int p; p = 0;
	for (int i = 0; i < v1.size(); i++) {
		v1[i] = 0;
	};
	for (int j = 0; j < tokens2.size(); j++)
	{
		word = tokens2[j];
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] == word)
			{
				tokens[i] = ' ';
				v1[p] = v1[p] + 1;
			}
		}p = p + 1;
	}
	for (int j = 0; j < tokens.size(); j++)
	{
		word = tokens[j];
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] == word)
			{
				tokens[i] = ' ';
				v1[p] = v1[p] + 1;
			}
		} p = p + 1;
	}



	cout << "la similarité de se deux fichiers txt est :" << endl;
	cout << cosineSimilarity(v1, v2);






}
