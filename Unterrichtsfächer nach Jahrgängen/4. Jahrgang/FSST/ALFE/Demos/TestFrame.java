import javax.swing.*;
 
public class TestFrame
{
    public static void main(String[] args)
    {
        JFrame meinJFrame = new JFrame();
        meinJFrame.setTitle("JButton Beispiel");
        JPanel panel = new JPanel();
 
        // JButton mit Text "Drück mich" wird erstellt
        JButton button = new JButton("Drück mich");
 
        // JButton wird dem Panel hinzugefügt
        panel.add(button);
 
        meinJFrame.add(panel);
 
        // Fenstergröße wird so angepasst, dass 
        // der Inhalt reinpasst    
        meinJFrame.pack();
 
        meinJFrame.setVisible(true);
    }
}