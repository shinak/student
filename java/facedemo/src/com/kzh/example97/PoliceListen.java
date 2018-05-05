package com.kzh.example97;

import java.awt.event.ActionEvent;

import javax.swing.JTextArea;
import javax.swing.JTextField;

public class PoliceListen implements MyCommandListener {
	JTextField textInput;
	JTextArea textShow;

	public void setJTextField(JTextField text) {
		textInput = text;
	}
	public void setJTextArea(JTextArea area) {
		textShow = area;
	}

	public void actionPerformed(ActionEvent e){
		String string = textInput.getText();
		textShow.append(string+"length:"+string.length()+"\n");
	}

}
