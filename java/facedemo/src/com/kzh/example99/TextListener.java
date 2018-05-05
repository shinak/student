package com.kzh.example99;

import java.util.Arrays;

import javax.swing.JTextArea;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

public class TextListener implements DocumentListener {
	JTextArea inputArea,outArea;
	public void setInputText(JTextArea textArea) {
		inputArea = textArea;
	}
	
	public void setOutText(JTextArea textArea) {
		outArea = textArea;
	}

	@Override
	public void changedUpdate(DocumentEvent arg0) {
		// TODO Auto-generated method stub
		String str = inputArea.getText();
		
		String regex = "[\\s\\d\\p{Punct}]+";
		String words[] = str.split(regex);
		Arrays.sort(words);
		outArea.setText(null);
		for(int i=0;i<words.length;i++){
			outArea.append(words[i]+",");
		}
	}

	@Override
	public void insertUpdate(DocumentEvent arg0) {
		// TODO Auto-generated method stub
		changedUpdate(arg0);
	}

	@Override
	public void removeUpdate(DocumentEvent arg0) {
		// TODO Auto-generated method stub
		changedUpdate(arg0);
	}

}
