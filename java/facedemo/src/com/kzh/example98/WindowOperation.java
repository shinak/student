package com.kzh.example98;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import com.sun.org.apache.xml.internal.security.Init;

public class WindowOperation extends JFrame{
	JTextField inputNumberOne,inputNumberTwo;
	JComboBox choiceFuhao;
	JTextArea textShow;
	JButton button;
	OperatorListener operator;
	ComputerListener computer;
	public WindowOperation(){
		init();
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	void init(){
		setLayout(new FlowLayout());
		inputNumberOne = new JTextField(5);
		inputNumberTwo = new JTextField(5);
		choiceFuhao = new JComboBox();
		button = new JButton("count");
		choiceFuhao.addItem("choose count symbol");
		String[] a = {"+","-","*","/"};
		for(int i=0;i<a.length;i++){
			choiceFuhao.addItem(a[i]);
		}
		textShow = new JTextArea(9,30);
		operator = new OperatorListener();
		computer = new ComputerListener();
		operator.setJComboBox(choiceFuhao);
		operator.setWorkTogether(computer);
		computer.setJTextFieldOne(inputNumberOne);
		computer.setJTextFieldTwo(inputNumberTwo);
		computer.setJTextArea(textShow);
		choiceFuhao.addItemListener(operator);
		button.addActionListener(computer);
		add(inputNumberOne);
		add(choiceFuhao);
		add(inputNumberTwo);
		add(button);
		add(new JScrollPane(textShow));
	}
}
