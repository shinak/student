package com.kzh.facetest;

import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class PanelNullLayout extends JPanel{
	JButton button;
	JTextField textField;
	public PanelNullLayout() {
		// TODO Auto-generated constructor stub
		setLayout(null);//空布局
		button = new JButton("确定");
		textField = new JTextField();
		this.add(textField);
		this.add(button);
		textField.setBounds(100, 30, 90, 30);
		button.setBounds(190, 30, 66, 30);
	}
}
