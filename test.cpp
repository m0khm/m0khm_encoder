#include <iostream>
#include <bitset>
#include <string>
#include <locale>
#include <codecvt>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <tuple>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для преобразования строки в двоичное представление
string stb(const string & str) {
	string binaryString = "";
	for (char c : str) {
		binaryString += bitset<8>(c).to_string();
	}
	return binaryString;
}

// Функция для преобразования двоичной строки обратно в текстовую строку
string bts(const string& binaryStr) {
	string textString = "";
	for (size_t i = 0; i < binaryStr.size(); i += 8) {
		textString += static_cast<char>(bitset<8>(binaryStr.substr(i, 8)).to_ulong());
	}
	return textString;
}
//Функция для побитовой операции XOR
string xoro(const string& binaryString, const string& password) {
	string xorResult = "";
	for (size_t i = 0; i < binaryString.length(); i += 8) {
		bitset<8> bits(binaryString.substr(i, 8));
		bitset<8> passwordBits(password[i / 8 % password.length()]);
		bitset<8> resultBits = bits ^ passwordBits;
		xorResult += resultBits.to_string();
	}
	return xorResult;
}
// Функция для декодирования XOR-результата обратно в строку
string decoder(const string& password, const string& xorResult) {
	string decodedString = "";
	for (size_t i = 0; i < xorResult.length(); i += 8) {
		bitset<8> bits(xorResult.substr(i, 8));
		bitset<8> passwordBits(password[i / 8 % password.length()]);
		bitset<8> resultBits = bits ^ passwordBits;
		char decodedChar = static_cast<char>(resultBits.to_ulong());
		decodedString += decodedChar;
	}
	return decodedString;
}
//Функция для декодирования символьных зашифрованных значений (case 4)
string decoder_char(const string& passwordsh, const string& ciphersh) {
	string decodedString = "";
	string binaryp = "";
	string binarys = "";
	binaryp = stb(passwordsh);
	binarys = stb(ciphersh);
	decodedString = decoder(binaryp, binarys);
	return decodedString;
}


// Исполнительная функция
tuple <string, string> exec(const string& input) {
	string binaryString = "";

	// Перевод каждого символа в двоичную систему
	binaryString = stb(input);

	// Генерация пароля той же длины, что и двоичная строка
	string password = "";
	for (size_t i = 0; i < binaryString.length(); i += 8) {
		password += bitset<8>(rand() % 256).to_string(); // Генерация случайного байта пароля
	}

	// Выполнение побитовой операции XOR между паролем и двоичной строкой
	string xorResult = xoro(binaryString, password);
	return make_tuple(xorResult, password);
}
// UPD: Ведётся разработка...
// UPD: Development is underway...
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
// Функция для преобразования строки в двоичную строку
wstring rstb(const wstring& str) {
	wstring binaryString = L"";
	for (wchar_t wc : str) {
		binaryString += wstring(bitset<8>(wc).to_string().begin(), bitset<8>(wc).to_string().end());
	}
	return binaryString;
}

// Функция для преобразования двоичной строки обратно в текстовую строку
wstring rbts(const wstring& binaryStr) {
	wstring textString = L"";
	for (size_t i = 0; i < binaryStr.size(); i += 8) {
		textString += static_cast<wchar_t>(bitset<8>(binaryStr.substr(i, 8)).to_ulong());
	}
	return textString;
}

// Функция для побитовой операции XOR
wstring rxoro(const wstring& binaryString, const wstring& password) {
	wstring xorResult = L"";
	for (size_t i = 0; i < binaryString.length(); i += 8) {
		bitset<8> bits(binaryString.substr(i, 8));
		bitset<8> passwordBits(password.substr(i, 8));
		bitset<8> resultBits = bits ^ passwordBits;
		xorResult += wstring(resultBits.to_string().begin(), resultBits.to_string().end());
	}
	return xorResult;
}

// Функция для декодирования
wstring rdecoder(const wstring& password, const wstring& xorResult) {
	return rbts(rxoro(xorResult, password));
}

// Исполнительная функция
tuple<wstring, wstring> rexec(const wstring& input) {
	wstring binaryString = rstb(input);
	srand(static_cast<unsigned int>(time(nullptr)));
	// Генерация пароля той же длины, что и двоичная строка
	wstring password = L"";
	for (size_t i = 0; i < binaryString.length(); i += 8) {
		password += wstring(bitset<8>(rand() % 256).to_string().begin(), bitset<8>(rand() % 256).to_string().end());
	}

	// Выполнение побитовой операции XOR между паролем и двоичной строкой
	wstring xorResult = rxoro(binaryString, password);
	return make_tuple(xorResult, password);
}*/
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Основная функция
int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	cout << "Добро пожаловать в программу шифратор-кодировщик(дешифратор-декодировщик)\n";
	cout << "Please choose a language:\nПожалуйста выбери язык\n1)Russian\n2)English\n\n\n";
	cout << "[Шифрование пока доступно только на English(пока не придумал как переводить русские символы)\n\
Encryption is currently only available in English (I haven't figured out how to translate Russian characters yet)]";
	//Шифрование пока доступно только на English(пока не придумал как переводить русские символы)
	//Encryption is currently only available in English (I haven't figured out how to translate Russian characters yet)
	int language;
	cin >> language;
	system("cls");
	cin.ignore();
	
	switch (language) {
		//---------------------------------------------------------------------------------------------------------------------------------------------------------
	case 1: {
		/*
		wstring cipher, password;
		int chose;
		cout << "Выберите операцию:\n1)Зашифровать строку и получить пароль расшифровки.\n2)Расшифровать шифр.(bin)\n3)Зашифровать строку и расшифровать ее.(bin)\n";
		cin >> chose;
		cin.ignore();
		
		switch (chose) {
		case 1: {
			system("cls");
			wstring input;
			cout << "Введите строку: ";
			getline(wcin, input);
			tie(cipher, password) = rexec(input);
			system("cls");
			
			printf("Ваш пароль расшифровки: %s\n", password.c_str());
			break;
		}
		case 2: {

			system("cls");

			cout << "Введите пароль расшифровки и шифр через пробел.";
			wstring pas, shifr;
			wcin >> pas >> shifr;
			wstring decodedString = rdecoder(pas, shifr);
			system("cls");
			printf("Ваш расшифрованный текст: %s\n", decodedString.c_str());
			break;
		}
		case 3: {
			system("cls");
			wstring input;
			cout << "Введите строку: ";
			getline(wcin, input);

			tie(cipher, password) = rexec(input);
			wstring decodedString = rdecoder(password, cipher);

			system("cls");

			printf("Ваш шифр: %s\n", cipher.c_str());
			printf("Ваш пароль расшифровки: %s\n", password.c_str());
			printf("Ваш расшифрованный текст: %s\n", decodedString.c_str());
			break;
		}
		default: {
			abort();
			break; }

		}
		*/
		break;

	}
	 //------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	case 2: {
		string cipher, password;
		int chose;
		cout << "Выберите операцию:\n\
1)Зашифровать строку и получить пароль расшифровки.\n\
2)Расшифровать шифр.(bin)\n\
3)Зашифровать строку и расшифровать ее.(bin)\n\
4)Зашировать строку и получить пароль расшифровки.(char)\n\
5)Расшифровать шифр.(char)\n\
6)Зашифровать строку и расшифровать ее.(char)\n";
		cin >> chose;
		cin.ignore();

		switch (chose) {
		case 1: {
			system("cls");
			string input;
			cout << "Введите строку: ";
			getline(cin, input);
			tie(cipher, password) = exec(input);
			system("cls");
			printf("Ваш шифр: %s\n", cipher.c_str());
			printf("Ваш пароль расшифровки: %s\n", password.c_str());
			break;
		}
		case 2: {
			system("cls");
			cout << "Введите пароль расшифровки и шифр через пробел.";
			string pas, shifr;
			cin >> pas >> shifr;
			string decodedString = decoder(pas, shifr);
			system("cls");
			printf("Ваш расшифрованный текст: %s\n", decodedString.c_str());
			break;
		}
		case 3: {
			system("cls");
			string input;
			cout << "Введите строку: ";
			getline(cin, input);
			tie(cipher, password) = exec(input);
			string decodedString = decoder(password, cipher);
			system("cls");
			printf("Ваш шифр: %s\n", cipher.c_str());
			
			printf("Ваш пароль расшифровки: %s\n", password.c_str());
			printf("Ваш расшифрованный текст: %s\n", decodedString.c_str());
			break;
		}
		case 4: {
			system("cls");
			string input;
			cout << "Введите строку: ";
			getline(cin, input);
			tie(cipher, password) = exec(input);
			string ciphersh = bts(cipher);
			string passwordsh = bts(password);
			system("cls");
			printf("Ваш шифр: %s\n", ciphersh.c_str());
			printf("Ваш пароль расшифровки: %s\n", passwordsh.c_str());
			break;
		}
		case 5: {
			system("cls");
			cout << "Введите пароль расшифровки и шифр через пробел.";
			string cipersh, passwordsh;
			cin >> cipersh >> passwordsh;
			string decodedString = decoder_char(passwordsh, cipersh);
			system("cls");
			printf("Ваш расшифрованный текст: %s\n", decodedString.c_str());
			break;
		}
		case 6: {
			system("cls");
			string input;
			cout << "Введите строку: ";
			getline(cin, input);
			tie(cipher, password) = exec(input);
			string ciphersh = bts(cipher);
			string passwordsh = bts(password);
			string decodedString = decoder_char(passwordsh, ciphersh);
			system("cls");
			printf("Ваш шифр: %s\n", ciphersh.c_str());
			printf("Ваш пароль расшифровки: %s\n", passwordsh.c_str());
			printf("Ваш расшифрованный текст: %s\n", decodedString.c_str());
			break;
		}
			 
		default:
			cout << "Такая команда не предусмотрена!";
			Sleep(2000);
			abort();
		}
		break;
	}
	default: {cout << " This language is not yet supported\nЭтот язык пока не поддерживается"; Sleep(2000); abort(); }
	}
		   return 0;
	}
