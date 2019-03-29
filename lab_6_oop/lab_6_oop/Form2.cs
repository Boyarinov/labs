using System;
using System.Windows.Forms;

namespace lab_6_oop
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        private void Form2_Load(object sender, EventArgs e) {   }

        private void button1_Click(object sender, EventArgs e)
        {
            string s1 = (textBox1.Text);
            if (!Utility.IsValidString(s1))
                s1 = "0";
            string s2 = (textBox2.Text);
            if (!Utility.IsValidString(s2))
                s2 = "0";
            RomanFigure rom1 = new RomanFigure(s1), rom2 = new RomanFigure(s2);
            RomanFigure sum;
            sum = rom1 + rom2;
            textBox3.Text = rom1.GetDecimal().ToString();
            if (textBox3.Text == "0")
                textBox3.Text = "error";
            textBox4.Text = rom2.GetDecimal().ToString();
            if (textBox4.Text == "0")
                textBox4.Text = "error";
            textBox5.Text = sum.GetRoman();
            textBox6.Text = sum.GetDecimal().ToString();
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
