package com.test.jd;

import java.sql.Connection;
import java.sql.DriverManager;
 
public class TEST {
     
    //mysql���ݿ��������̶�д��������Oracleʱ����֮��ͬ,Ϊ��"oracle.jdbc.driver.OracleDriver"
    private static final String driver = "com.mysql.jdbc.Driver"; 
 
    /**
    * �������������ݿ��URL��ַ��
    * ���У�"jdbc:mysql://"   Ϊ�̶�д��
    * "localhost"�����ӱ������ݿ�ʱ��д�������������ӱ������ݿ�ʱ��Ҫд���ݿ����ڼ������IP��ַ���磺172.26.132.253
    * "shopping"�����ݿ�����ƣ�һ��Ҫ�����Լ������ݿ���ġ�
    * "?useUnicode=true&characterEncoding=UTF-8" ָ�������ʽ������ʱ��ʡ�ԣ�
    * ����ֱַ��Ϊ��"jdbc:mysql://localhost:3306/shopping"
    */
    private static final String url="jdbc:mysql://localhost:3306/shopping?useUnicode=true&characterEncoding=UTF-8"; 
     
    private static final String username="root";//���ݿ���û���
    private static final String password="root";//���ݿ������:������Լ���װ���ݿ��ʱ�����õģ�ÿ���˲�ͬ��
     
    private static Connection conn=null;  //�������ݿ����Ӷ���
     
    //��̬����鸺���������
    static
    {
        try
        {
            Class.forName(driver);
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
    }
     
    //����ģʽ�������ݿ����Ӷ��󣬹��ⲿ����
    public static Connection getConnection() throws Exception
    {
        if(conn==null)
        {
            conn = DriverManager.getConnection(url, username, password); //�������ݿ�
            return conn;
        }
        return conn;
    }
     
    //дmain���������Ƿ����ӳɹ����ɽ���������ΪJava�����Ƚ��в��ԣ��������������ݿ������
    public static void main(String[] args) {
         
        try
        {
           Connection conn = TEST.getConnection();
           if(conn!=null)
           {
               System.out.println("���ݿ�����������");
           }
           else
           {
               System.out.println("���ݿ������쳣��");
           }
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
         
    }
}
