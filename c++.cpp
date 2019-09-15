#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <random>
using namespace std;

// Global variables for working inside the functions
// Each variable represents the relative probability of nucleotide bigram.
float aa = 0.0;
float ac = 0.0;
float at = 0.0;
float ag = 0.0;
float ca = 0.0;
float cc = 0.0;
float ct = 0.0;
float cg = 0.0;
float ta = 0.0;
float tc = 0.0;
float tt = 0.0;
float tg = 0.0;
float ga = 0.0;
float gc = 0.0;
float gt = 0.0;
float gg = 0.0;

//Function for calculating nucleotide bigrams
void CalcBigram(char current, char next)
{
	// current = letter currently being read in the file, next = letter next to the current letter
	if (current == 'A' || current == 'a')
	{
		//if current letter is A, next letter is A
		if (tolower(next) == 'a')
		{
			aa++;
		}
		//next letter is C
		else if (tolower(next) == 'c')
		{
			ac++;
		}
		//next letter is T
		else if (tolower(next) == 't')
		{
			at++;
		}
		//next letter is G
		else if (tolower(next) == 'g')
		{
			ag++;
		}
		//if next letter doesn't match, prints error statement
		else
		{
			cout << "ERROR" << endl;
		}
	}
	else if (current == 'C' || current == 'c')
	{
		//if current letter is C, next letter is A
		if (tolower(next) == 'a')
		{
			ca++;
		}
		//next letter is C
		else if (tolower(next) == 'c')
		{
			cc++;
		}
		//next letter is T
		else if (tolower(next) == 't')
		{
			ct++;
		}
		//next letter is G
		else if (tolower(next) == 'g')
		{
			cg++;
		}
		//if next letter doesn't match, prints error statement
		else
		{
			cout << "ERROR" << endl;
		}
	}
	else if (current == 'T' || current == 't')
	{
		//if current letter is T, next letter is A
		if (tolower(next) == 'a')
		{
			ta++;
		}
		//next letter is C
		else if (tolower(next) == 'c')
		{
			tc++;
		}
		//next letter is T
		else if (tolower(next) == 't')
		{
			tt++;
		}
		//next letter is G
		else if (tolower(next) == 'g')
		{
			tg++;
		}
		//if next letter doesn't match, prints error statement
		else
		{
			cout << "ERROR" << endl;
		}
	}
	else if (current == 'G' || current == 'g')
	{
		//if current letter is G, next letter is A
		if (tolower(next) == 'a')
		{
			ga++;
		}
		//next letter is C
		else if (tolower(next) == 'c')
		{
			gc++;
		}
		//next letter is T
		else if (tolower(next) == 't')
		{
			gt++;
		}
		//next letter is G
		else if (tolower(next) == 'g')
		{
			gg++;
		}
		//if next letter doesn't match, prints error statement
		else
		{
			cout << "ERROR" << endl;
		}
	}
	//if no letters match from the beginning, prints error statement
	else
		std::cout << "ERROR: Does not work.";
}

int main()
{
	//allows user to type in whichever text file they want to read in
	string textname;
	cout << "Type text file name: " << endl;
	cin >> textname;

	//reading in text file
	ifstream myfile;
	myfile.open("C:\\Users\\debbi\\source\\repos\\cpsc350assign1\\cpsc350assign1\\" + textname); 
	string line;
	float sum = 0.0;
	float numberOfLines = 0.0;
	float mean = 0.0;
	float variance = 0.0;
	float standard_deviation = 0.0;
	float a = 0.0;
	float c = 0.0;
	float t = 0.0;
	float g = 0.0;

	//loop to go through each line of the text file
	while (getline(myfile, line))
	{
		//for loop to go through each letter of the line
		for (int i = 0; i < line.length(); ++i)
		{
			//if statements for identifying letters in the text file
			if (line[i] == 'A' || line[i] == 'a')
			{
				sum++;
				a++;
				if (i != line.length() - 1)
				{
					CalcBigram(line[i], line[i + 1]);
				}
			}
			else if (line[i] == 'C' || line[i] == 'c')
			{
				sum++;
				c++;
				if (i != line.length() - 1)
				{
					CalcBigram(line[i], line[i + 1]);
				}
			}
			else if (line[i] == 'T' || line[i] == 't')
			{
				sum++;
				t++;
				if (i != line.length() - 1)
				{
					CalcBigram(line[i], line[i + 1]);
				}
			}
			else if (line[i] == 'G' || line[i] == 'g')
			{
				sum++;
				g++;
				if (i != line.length() - 1)
				{
					CalcBigram(line[i], line[i + 1]);
				}
			}
			else
			{
				std::cout << "ERROR: Does not work.";
			}
		}
		numberOfLines++;
	}

	mean = sum / numberOfLines;

	myfile.close();

	// opening the file again to calculate variance and standard deviation
	myfile.open("C:\\Users\\debbi\\source\\repos\\cpsc350assign1\\cpsc350assign1\\" + textname);
	float tempLength = 0.0;
	float tempTotal = 0.0;

	while (getline(myfile, line))
	{
		//tempLength calculates the difference between the length of the line and the mean and squares it
		tempLength = pow(line.length() - mean, 2);
		//tempTotal adds all numbers from tempLength to calculate part of variance
		tempTotal += tempLength;
	}

	variance = tempTotal / numberOfLines;
	standard_deviation = sqrt(variance);

	//equations for calculating relative probability of nucleotides and bigrams
	a = a / sum;
	c = c / sum;
	t = t / sum;
	g = g / sum;

	aa = aa / sum;
	ac = ac / sum;
	at = at / sum;
	ag = ag / sum;
	ca = ca / sum;
	cc = cc / sum;
	ct = ct / sum;
	cg = cg / sum;
	ta = ta / sum;
	tc = tc / sum;
	tt = tt / sum;
	tg = tg / sum;
	ga = ga / sum;
	gc = gc / sum;
	gt = gt / sum;
	gg = gg / sum;

	myfile.close();
	
	//printing all output into a file called "DebbieLu.out"
	ofstream outfile;
	outfile.open("DebbieLu.out");
	outfile << "Debbie Lu" << endl;
	outfile << "Student ID #: 2292435" << endl;
	outfile << "CPSC 350 - Section 2" << endl;
	outfile << "September 14, 2019" << endl;

	cout << "Debbie Lu" << endl;
	cout << "Student ID #: 2292435" << endl;
	cout << "CPSC 350 - Section 2" << endl;
	cout << "September 14, 2019" << endl;

	outfile << endl;
	cout << endl;

	outfile << "The length of the DNA is: " << sum << endl;
	outfile << "The number of lines of strings in the file is: " << numberOfLines << endl;
	outfile << "The sum of the strings is: " << sum << endl;
	outfile << "The mean of the strings is: " << mean << endl;
	outfile << "The variance of the strings is: " << variance << endl;
	outfile << "The standard deviation of the strings is: " << standard_deviation << endl;

	cout << "The length of the DNA is: " << sum << endl;
	cout << "The number of lines of strings in the file is: " << numberOfLines << endl;
	cout << "The sum of the strings is: " << sum << endl;
	cout << "The mean of the strings is: " << mean << endl;
	cout << "The variance of the strings is: " << variance << endl;
	cout << "The standard deviation of the strings is: " << standard_deviation << endl;

	outfile << endl;
	cout << endl;

	outfile << "The relative probability of nucleotide A is: " << a << endl;
	outfile << "The relative probability of nucleotide C is: " << c << endl;
	outfile << "The relative probability of nucleotide T is: " << t << endl;
	outfile << "The relative probability of nucleotide G is: " << g << endl;

	cout << "The relative probability of nucleotide A is: " << a << endl;
	cout << "The relative probability of nucleotide C is: " << c << endl;
	cout << "The relative probability of nucleotide T is: " << t << endl;
	cout << "The relative probability of nucleotide G is: " << g << endl;

	outfile << endl;
	cout << endl;
	
	outfile << "The relative probability of nucleotide bigram AA is: " << aa << endl;
	outfile << "The relative probability of nucleotide bigram AC is: " << ac << endl;
	outfile << "The relative probability of nucleotide bigram AT is: " << at << endl;
	outfile << "The relative probability of nucleotide bigram AG is: " << ag << endl;
	outfile << "The relative probability of nucleotide bigram CA is: " << ca << endl;
	outfile << "The relative probability of nucleotide bigram CC is: " << cc << endl;
	outfile << "The relative probability of nucleotide bigram CT is: " << ct << endl;
	outfile << "The relative probability of nucleotide bigram CG is: " << cg << endl;
	outfile << "The relative probability of nucleotide bigram TA is: " << ta << endl;
	outfile << "The relative probability of nucleotide bigram TC is: " << tc << endl;
	outfile << "The relative probability of nucleotide bigram TT is: " << tt << endl;
	outfile << "The relative probability of nucleotide bigram TG is: " << tg << endl;
	outfile << "The relative probability of nucleotide bigram GA is: " << ga << endl;
	outfile << "The relative probability of nucleotide bigram GC is: " << gc << endl;
	outfile << "The relative probability of nucleotide bigram GT is: " << gt << endl;
	outfile << "The relative probability of nucleotide bigram GG is: " << gg << endl;

	cout << "The relative probability of nucleotide bigram AA is: " << aa << endl;
	cout << "The relative probability of nucleotide bigram AC is: " << ac << endl;
	cout << "The relative probability of nucleotide bigram AT is: " << at << endl;
	cout << "The relative probability of nucleotide bigram AG is: " << ag << endl;
	cout << "The relative probability of nucleotide bigram CA is: " << ca << endl;
	cout << "The relative probability of nucleotide bigram CC is: " << cc << endl;
	cout << "The relative probability of nucleotide bigram CT is: " << ct << endl;
	cout << "The relative probability of nucleotide bigram CG is: " << cg << endl;
	cout << "The relative probability of nucleotide bigram TA is: " << ta << endl;
	cout << "The relative probability of nucleotide bigram TC is: " << tc << endl;
	cout << "The relative probability of nucleotide bigram TT is: " << tt << endl;
	cout << "The relative probability of nucleotide bigram TG is: " << tg << endl;
	cout << "The relative probability of nucleotide bigram GA is: " << ga << endl;
	cout << "The relative probability of nucleotide bigram GC is: " << gc << endl;
	cout << "The relative probability of nucleotide bigram GT is: " << gt << endl;
	cout << "The relative probability of nucleotide bigram GG is: " << gg << endl;

	outfile << endl;
	cout << endl;

	
	//1000 strings generated 
	for (int i = 0; i < 1000; ++i)
	{
		//calculations for Gaussian distribution
		double alpha, beta;
		alpha = rand() * (1.0 / RAND_MAX);
		beta = rand() * (1.0 / RAND_MAX);

		float gamma, delta;
		gamma = sqrt((-2.0 * log(alpha)) * cos(M_PI_2 * beta));
		delta = (sqrt(variance) * gamma) + mean;
	
		//prints the 1000 strings
		outfile << "DNA String #" << i + 1 << ": " << delta << endl;
		cout << "DNA String #" << i + 1 << ": " << delta << endl;
	}
	
	//loop to process another list if user wants to
	while (true)
	{
		char answer;
		cout << "Do you want to process another list? y = yes, n = no " << endl;
		cin >> answer;

		if (answer == 'y')
		{
			for (int i = 0; i < 1000; ++i)
			{
				double alpha, beta;
				alpha = rand() * (1.0 / RAND_MAX);
				beta = rand() * (1.0 / RAND_MAX);

				float gamma, delta;
				gamma = sqrt((-2.0 * log(alpha)) * cos(M_PI_2 * beta));
				delta = (sqrt(variance) * gamma) + mean;


				outfile << "DNA String Length #" << i + 1 << ": " << delta << endl;
				cout << "DNA String Length #" << i + 1 << ": " << delta << endl;
			}
		}
		else if (answer == 'n')
			break;
		else
			cout << "Incorrect input, please type y for yes, n for no: " << endl;
	}

	outfile.close();
}