package com.kzh.example99;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JTextArea;

import sun.nio.ch.SocketOpts.IP;

public class HandleListener implements ActionListener {
	JTextArea inputArea,outArea;
	public void setInputText(JTextArea text) {
		inputArea = text;
	}
	
	public void setOutText(JTextArea text) {
		outArea = text;
	}
	
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		String str = arg0.getActionCommand();
		if(str.equals("copy"))
			outArea.copy();
		else if(str.equals("cut"))
			outArea.cut();
		else if(str.equals("paste"))
			inputArea.paste();	
	}

}
