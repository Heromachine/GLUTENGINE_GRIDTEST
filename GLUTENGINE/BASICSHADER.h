#ifndef BASIC_SHADER_H
#define BASIC_SHADER_H
#include<string>
#include<GL\glew.h>
#include <iostream>
#include <fstream>
using namespace std;
class BasicShader
{
public:
	BasicShader(const string &fileName)
	{
	
	}
	BasicShader(int i)
	{
		cout << i <<"dddddddddddddddddddddddd";
		InitShader();
	
	}
	void Bind();

	//Shader();
	GLuint CreateShader(const string & text, GLenum shaderType);

	virtual ~BasicShader()
	{
		glDeleteProgram(shaderProgramID);
	}

	GLuint makeVertexShader(const char* shaderSource)
	{
		cout << "WORKED";
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShaderID, 1, (const GLchar**)&shaderSource, NULL);
		glCompileShader(vertexShaderID);
		return vertexShaderID; 	
	}

	GLuint makeFragmentShader(const char* shaderSource)
	{
		GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShaderID, 1, (const GLchar**)&shaderSource, NULL);
		glCompileShader(fragmentShaderID);
		return fragmentShaderID;	
	}

	GLuint makeShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
	{
		GLuint shaderID = glCreateProgram();
		glAttachShader(shaderID, vertexShaderID);
		glAttachShader(shaderID, fragmentShaderID);

		glLinkProgram(shaderID);
		CheckShaderError(shaderID, GL_LINK_STATUS, true, "\nERROR: program linking failed: ");

		glValidateProgram(shaderID);
		CheckShaderError(shaderID, GL_VALIDATE_STATUS, true, "\nERROR: program validation failed: ");

		cout << "WORKED";


		return shaderID;	
	}

	void InitShader()
	{
		cout << "WORKED";
		//char* vertexShaderSource = readFile("BasicShader.vs");
		//char* fragmentShaderSource = readFile("BasicShader.fs");

		char* vertexShaderSource = LoadCharShader("./res/basicShader.vs");
		char* fragmentShaderSource = LoadCharShader("./res/basicShader.fs");

		vertexShaderID = makeVertexShader(vertexShaderSource);
		fragmentShaderID = makeFragmentShader(fragmentShaderSource);
		shaderProgramID = makeShaderProgram(vertexShaderID, fragmentShaderID);
		glUseProgram(shaderProgramID);

	}

	static string LoadShader(const string& fileName)
	{
		ifstream file;
		file.open((fileName).c_str());

		string output;
		string line;

		if (file.is_open())
		{
			//cout << "\nFILE " << fileName<< " is open"<< endl;
			//while (file.good())
			//{
			//	getline(file, line);
			//	output.append(line + "\n");
			//	cout << "\n " <<line <<" \n";
			//}
		}
		else
		{
			cerr << "\nUNABLE TO LOAD SHADER" << fileName << endl;
		}

		return output;
	}
	static char* LoadCharShader(const string& fileName)
	{
		ifstream file;
		file.open((fileName).c_str());

		
		string output;
		string line;

		if (file.is_open())
		{
			//cout << "\nFILE " << fileName<< " is open"<< endl;
			//while (file.good())
			//{
			//	getline(file, line);
			//	output.append(line + "\n");
			//	cout << "\n " <<line <<" \n";
			//}
		}
		else
		{
			cerr << "\nUNABLE TO LAOD SHADER" << fileName << endl;
		}


		char *op = new char[output.length() +1];
		strcpy(op, output.c_str());
		return op;
	}
	static char * readFile(const char* fileName)
	{

		FILE* fp = fopen(fileName, "r");
		
		fseek(fp, 0, SEEK_END);
		long file_length = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		char* contents = new char[file_length + 1];
		for (int i = 0; i < file_length + 1; i++)
		{
			contents[i] = 0;
		}

		fread(contents, 1 ,file_length, fp);
		contents[file_length + 1] = 0;
		fclose(fp);
		return contents; 

	
	}
	static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage)
	{
		GLint success = 0;
		GLchar error[1024] = { 0 };

		if (isProgram)
		{
			glGetProgramiv(shader, flag, &success);
		}
		else
		{
			glGetShaderiv(shader, flag, &success);
		}


		//
		if (success == GL_FALSE)
		{
			if (isProgram)
			{
				glGetProgramInfoLog(shader, sizeof(error), NULL, error);
			}
			else
			{
				glGetShaderInfoLog(shader, sizeof(error), NULL, error);
			}

			cerr << errorMessage << ": [ " << error << " ]\n" << endl;
		}
	}





private:
	BasicShader(const BasicShader& other);
	void operator =(const BasicShader& other) {}

	static const unsigned int NUM_SHADERS = 2;

	GLuint vertexShaderID;
	GLuint fragmentShaderID;
	GLuint shaderProgramID;

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];




};



#endif 
