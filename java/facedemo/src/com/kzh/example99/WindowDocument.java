package com.kzh.example99;

import java.awt.FlowLayout;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.KeyStroke;

public class WindowDocument extends JFrame{
	JTextArea textAreaOne,textAreaTwo;
	JMenuBar menuBar;
	JMenu menu;
	JMenuItem menuItemOne,menuItemTwo,menuItemThree;
	TextListener textChangeListener;
	HandleListener handleListener;
	public WindowDocument() {
		// TODO Auto-generated constructor stub
		init();
		setLayout(new FlowLayout());
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public void init(){
		textAreaOne = new JTextArea(15,20);
		textAreaTwo = new JTextArea(15,20);
		textAreaTwo.setLineWrap(true);
		textAreaTwo.setWrapStyleWord(true);
		menuBar = new JMenuBar();
		menu = new JMenu("±à¼­");
		menuItemOne = new JMenuItem("copy(C)");
		menuItemTwo = new JMenuItem("cut(T)");
		menuItemThree = new JMenuItem("paste(P)");
		menuItemOne.setAccelerator(KeyStroke.getKeyStroke('c'));
		menuItemTwo.setAccelerator(KeyStroke.getKeyStroke('t'));
		menuItemThree.setAccelerator(KeyStroke.getKeyStroke('p'));
		menuItemOne.setActionCommand("copy");
		menuItemTwo.setActionCommand("cut");
		menuItemThree.setActionCommand("paste");
		menu.add(menuItemOne);
		menu.add(menuItemTwo);
		menu.add(menuItemThree);
		menuBar.add(menu);
		this.setJMenuBar(menuBar);
		add(new JScrollPane(textAreaOne));
		add(new JScrollPane(textAreaTwo));
		textChangeListener = new TextListener();
		handleListener = new HandleListener();
		textChangeListener.setInputText(textAreaOne);
		textChangeListener.setOutText(textAreaTwo);
		handleListener.setInputText(textAreaOne);
		handleListener.setOutText(textAreaTwo);
		(textAreaOne.getDocument()).addDocumentListener(textChangeListener);
		menuItemOne.addActionListener(handleListener);
		menuItemTwo.addActionListener(handleListener);
		menuItemThree.addActionListener(handleListener);
		
	}
}
