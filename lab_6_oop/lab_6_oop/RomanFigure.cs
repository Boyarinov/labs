using System;

namespace lab_6_oop
{
    class RomanFigure
    {
        string roman;
        int dec;

        public RomanFigure() {}

        public RomanFigure(string str)
        {
            roman = str;
            dec = Utility.RomanToDec(str);//в конструкторе сразу же происходит перевод из римского в десятичное
        }


        public string GetRoman() // Возвращает римское число
        {
            return this.roman;
        }
        public int GetDecimal() // Возвращает десятичное число
        {
            return this.dec;
        }
        public void SetRoman(string str)//Изменение значения
        {
            this.roman = str;
            this.dec = Utility.RomanToDec(str);
        }
        //RomanFigure add(RomanFigure &temp);//сложение двух римских чисел

        public static RomanFigure operator +(RomanFigure temp1, RomanFigure temp2)//сложение двух римских чисел с перегрузкой оператора 
        {
            string temp_roman = Utility.RemoveSubstr(temp2.GetRoman());
            string str_temp = Utility.RemoveSubstr(temp1.GetRoman());
            string new_roman = "";
            temp_roman += str_temp;
            char[] tmpch = temp_roman.ToCharArray();
            Array.Sort(tmpch, new RomanComparer());
            temp_roman = new string(tmpch);
            int ones, tens, hundreds, thousands;
            ones = tens = hundreds = thousands = 0;
            for (int i = 0; i < temp_roman.Length; i++)
            {
                switch (temp_roman[i])
                {
                    case 'I': ones += 1; break;
                    case 'V': ones += 5; break;
                    case 'X': tens += 1; break;
                    case 'L': tens += 5; break;
                    case 'C': hundreds += 1; break;
                    case 'D': hundreds += 5; break;
                    case 'M': thousands += 1; break;
                }
            }

            tens += ones / 10;
            ones %= 10;
            hundreds += tens / 10;
            tens %= 10;
            thousands += hundreds / 10;
            hundreds %= 10;

            new_roman += new string('M', thousands);
            if (hundreds == 9)
            {
                new_roman += "CM";
            }
            else if (hundreds == 4)
            {
                new_roman += "CD";
            }
            else
            {
                new_roman += new string('D', hundreds / 5) + new string('C' ,hundreds % 5);
            }

            if (tens == 9)
            {
                new_roman += "XC";
            }
            else if (tens == 4)
            {
                new_roman += "XL";
            }
            else
            {
                new_roman += new string('L', tens / 5) + new string('X', tens % 5);
            }

            if (ones == 9)
            {
                new_roman += "IX";
            }
            else if (ones == 4)
            {
                new_roman += "IV";
            }
            else
            {
                new_roman += new string('V', ones / 5) + new string('I', ones % 5);
            }
            return new RomanFigure(new_roman);
        }
    }
}
