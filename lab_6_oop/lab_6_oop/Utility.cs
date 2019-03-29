
using System.Collections.Generic;
using System.Linq;

namespace lab_6_oop
{
    class Utility
    {
        public static int RomanToNum(char str) // перевод римского символа в числовое представление
        {
            if (str == 'I')
                return 1;
            else if (str == 'V')
                return 5;
            else if (str == 'X')
                return 10;
            else if (str == 'L')
                return 50;
            else if (str == 'C')
                return 100;
            else if (str == 'D')
                return 500;
            else if (str == 'M')
                return 1000;
            else
                return 0;
        }

        public static string ReplaceSub(string str) // перевод римского числа к виду без вычитания
        {
            if (str == "IV")
                return "IIII";
            else if (str == "IX")
                return "VIIII";
            else if (str == "XL")
                return "XXXX";
            else if (str == "XC")
                return "LXXXX";
            else if (str == "CD")
                return "CCCC";
            else return "DCCCC";
        }
        public static string DecToRoman(int a) // перевод десятичного числа в римское
        {
            if (a == 0)
                return "I";
            else if (a == 5)
                return "V";
            else if (a == 10)
                return "X";
            else if (a == 50)
                return "L";
            else if (a == 100)
                return "C";
            else if (a == 500)
                return "D";
            else
                return "M";
        }

        public static int RomanToDec(string str) // Перевод из римского числа в десятичное
        {
            int buff = 0;
            int num = 0;
            for (int i = 0; i < str.Length; i++)
            {

                if ((i > 0) && (RomanToNum(str[i]) > RomanToNum(str[i - 1])))
                {
                    num += RomanToNum(str[i]) - buff;
                    buff = 0;
                }
                else
                {
                    num += buff;
                    buff = 0;
                    buff += RomanToNum(str[i]);
                }
            }
            num += buff;
            return num;
        }
        public static string[] substractions = { "IV", "IX", "XL", "XC", "CD", "CM" };
        public static string alphabet = "IVXLCDM";
        public static string RemoveSubstr(string a) // убирает все вычитания из римской записи числа
        {
            string new_a = a;
            for (int i = 0; i < 6; i++)
            {
                new_a = new_a.Replace(substractions[i], ReplaceSub(substractions[i]));
            }
            return new_a;
        }
        public static bool IsValidString(string str) // проверка, все ли символы строки есть в алфавите
        {
            foreach (char c in str)
            {
                if (!alphabet.Contains(c))
                    return false;
            }
            return true;
        }
    }
    class RomanComparer: IComparer<char>
    {
        public int Compare(char c1, char c2) // сравнение двух римских символов
        {
            if (Utility.RomanToNum(c1) > Utility.RomanToNum(c2))
                return 1;
            else if (Utility.RomanToNum(c1) < Utility.RomanToNum(c2))
                return -1;
            else
                return 0;
        }
    }
}

