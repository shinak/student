package com.kzh.example96;

import java.awt.FlowLayout;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JTextField;

public class WindowActionEvent extends JFrame{
	JTextField text;
	ActionListener listener;
	public WindowActionEvent() {
		setLayout(new FlowLayout());
		text = new JTextField(10);
		add(text);
		listener = new ReaderListen();
		text.addActionListener(listener);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
