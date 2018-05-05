package com.kzh.example98;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JTextArea;
import javax.swing.JTextField;

public class ComputerListener implements ActionListener {
	JTextField inputNumberOne,inputNumberTwo;
	JTextArea textShow;
	String fuhaoString;
	
	public void setJTextFieldOne(JTextField t) {
		inputNumberOne = t;
	}
	
	public void setJTextFieldTwo(JTextField t) {
		inputNumberTwo = t;
	}
	
	public void setJTextArea(JTextArea area) {
		textShow = area;
	}
	
	public void setFuhao(String s){
		fuhaoString = s;
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		try{
			double number1 = Double.parseDouble(inputNumberOne.getText());
			double number2 = Double.parseDouble(inputNumberTwo.getText());
			double result = 0;
			if(fuhaoString.equals("+")){
				result = number1 + number2;
			}
			else if(fuhaoString.equals("-")){
				result = number1 - number2;
			}
			else if(fuhaoString.equals("*")){
				result = number1 * number2;
			}
			else if(fuhaoString.equals("/")){
				result = number1 / number2;
			}
			textShow.append(number1 + " " + fuhaoString + " " + number2 + " = " + result + "\n");
			}
		catch (Exception exp) {
			// TODO: handle exception
			textShow.append("\nplease printf number symbol!\n");
		}
	}

}
