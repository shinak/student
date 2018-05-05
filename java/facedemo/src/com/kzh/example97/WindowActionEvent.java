package com.kzh.example97;

import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class WindowActionEvent extends JFrame{
	JTextField inputText;
	JTextArea textShow;
	JButton button;
	MyCommandListener listener;
	public WindowActionEvent(){
		init();
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	void init(){
		setLayout(new FlowLayout());
		inputText = new JTextField(10);
		button = new JButton("ok");
		textShow = new JTextArea(9,30);
		add(inputText);
		add(button);
		add(textShow);
		add(new JScrollPane(textShow));
	}
	void setMyCommandListener(MyCommandListener listener){
		this.listener = listener;
		listener.setJTextField(inputText);
		listener.setJTextArea(textShow);
		button.addActionListener(listener);
	}
}

