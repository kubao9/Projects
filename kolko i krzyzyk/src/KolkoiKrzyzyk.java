import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class KolkoiKrzyzyk implements ActionListener {


    Random random = new Random();
    JFrame frame = new JFrame();
    JPanel title_panel = new JPanel();
    JPanel button_panel = new JPanel();
    JLabel textfiled = new JLabel();
    JButton[] buttons = new JButton[9];
    boolean player1_turn;


    KolkoiKrzyzyk(){

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(800,800);
        frame.getContentPane().setBackground(new Color(50,50,50));
        frame.setLayout(new BorderLayout());
        frame.setVisible(true);

        textfiled.setBackground(Color.BLACK);
        textfiled.setForeground(Color.YELLOW);
        textfiled.setFont(new Font("Calibri",Font.BOLD,75));
        textfiled.setHorizontalAlignment(JLabel.CENTER);
        textfiled.setText("Kółko i krzyżyk");
        textfiled.setOpaque(true);

        title_panel.setLayout(new BorderLayout());
        title_panel.setBounds(0,0,800,100);

        button_panel.setLayout(new GridLayout(3,3));
        button_panel.setBackground(Color.GRAY);

        for (int i=0;i<9;i++)
        {
            buttons[i] = new JButton();
            button_panel.add(buttons[i]);
            buttons[i].setFont(new Font("Arial",Font.BOLD,120));
            buttons[i].setFocusable(false);
            buttons[i].addActionListener(this);
        }


        title_panel.add(textfiled);
        frame.add(title_panel,BorderLayout.NORTH);
        frame.add(button_panel);

        pierwszyRuch();

    }

    @Override
    public void actionPerformed(ActionEvent e) {

        for(int i=0;i<9;i++)
        {
            if(e.getSource()==buttons[i])
            {
                if(player1_turn)
                {
                    if(buttons[i].getText()=="")
                    {
                        buttons[i].setForeground(Color.RED);
                        buttons[i].setText("X");
                        player1_turn=false;
                        textfiled.setText("Ruch O");
                        sprawdz();
                    }
                }
                else
                {
                    if(buttons[i].getText()=="")
                    {
                        buttons[i].setForeground(Color.BLUE);
                        buttons[i].setText("O");
                        player1_turn=true;
                        textfiled.setText("Ruch X");
                        sprawdz();
                    }
                }
            }
        }
    }

    public void pierwszyRuch()
    {
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        if(random.nextInt(2)==0)
        {
            player1_turn = true;
            textfiled.setText("Ruch X");
            sprawdz();
        }
        else
        {
            player1_turn = false;
            textfiled.setText("Ruch O");
            sprawdz();
        }

    }

    public void sprawdz()
    {
        //warkunki do sprawdzenia dla X
        
        if((buttons[0].getText()=="X")&&
        (buttons[1].getText()=="X")&&
        (buttons[2].getText()=="X"))
        {
            xWygrywa(0,1,2);
        }

        if((buttons[3].getText()=="X")&&
                (buttons[4].getText()=="X")&&
                (buttons[5].getText()=="X"))
        {
            xWygrywa(3,4,5);
        }

        if((buttons[6].getText()=="X")&&
                (buttons[7].getText()=="X")&&
                (buttons[8].getText()=="X"))
        {
            xWygrywa(6,7,8);
        }

        if((buttons[0].getText()=="X")&&
                (buttons[3].getText()=="X")&&
                (buttons[6].getText()=="X"))
        {
            xWygrywa(0,3,6);
        }

        if((buttons[1].getText()=="X")&&
                (buttons[4].getText()=="X")&&
                (buttons[7].getText()=="X"))
        {
            xWygrywa(1,4,7);
        }

        if((buttons[2].getText()=="X")&&
                (buttons[5].getText()=="X")&&
                (buttons[8].getText()=="X"))
        {
            xWygrywa(2,5,8);
        }

        if((buttons[0].getText()=="X")&&
                (buttons[4].getText()=="X")&&
                (buttons[8].getText()=="X"))
        {
            xWygrywa(0,4,8);
        }

        if((buttons[2].getText()=="X")&&
                (buttons[4].getText()=="X")&&
                (buttons[6].getText()=="X"))
        {
            xWygrywa(2,4,6);
        }
        
        //warunki do sprawdzenia dla O

        if((buttons[0].getText()=="O")&&
                (buttons[1].getText()=="O")&&
                (buttons[2].getText()=="O"))
        {
            oWygrywa(0,1,2);
        }

        if((buttons[3].getText()=="O")&&
                (buttons[4].getText()=="O")&&
                (buttons[5].getText()=="O"))
        {
            oWygrywa(3,4,5);
        }

        if((buttons[6].getText()=="O")&&
                (buttons[7].getText()=="O")&&
                (buttons[8].getText()=="O"))
        {
            oWygrywa(6,7,8);
        }

        if((buttons[0].getText()=="O")&&
                (buttons[3].getText()=="O")&&
                (buttons[6].getText()=="O"))
        {
            oWygrywa(0,3,6);
        }

        if((buttons[1].getText()=="O")&&
                (buttons[4].getText()=="O")&&
                (buttons[7].getText()=="O"))
        {
            oWygrywa(1,4,7);
        }

        if((buttons[2].getText()=="O")&&
                (buttons[5].getText()=="O")&&
                (buttons[8].getText()=="O"))
        {
            oWygrywa(2,5,8);
        }

        if((buttons[0].getText()=="O")&&
                (buttons[4].getText()=="O")&&
                (buttons[8].getText()=="O"))
        {
            oWygrywa(0,4,8);
        }

        if((buttons[2].getText()=="O")&&
                (buttons[4].getText()=="O")&&
                (buttons[6].getText()=="O"))
        {
            oWygrywa(2,4,6);
        }
    }

    public void xWygrywa(int a, int b, int c)
    {
        buttons[a].setBackground(Color.GREEN);
        buttons[b].setBackground(Color.GREEN);
        buttons[c].setBackground(Color.GREEN);

        for (int i=0;i<9;i++)
        {
            buttons[i].setEnabled(false);
        }
        textfiled.setText("X wygrywa");

    }

    public void oWygrywa(int a, int b, int c)
    {
        buttons[a].setBackground(Color.GREEN);
        buttons[b].setBackground(Color.GREEN);
        buttons[c].setBackground(Color.GREEN);

        for (int i=0;i<9;i++)
        {
            buttons[i].setEnabled(false);
        }
        textfiled.setText("O wygrywa");
    }
}
