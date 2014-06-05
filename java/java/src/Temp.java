

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.Rectangle;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;
import javax.swing.JTextPane;
import javax.swing.JToolBar;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.event.CaretEvent;
import javax.swing.event.CaretListener;
import javax.swing.text.AbstractDocument;
import javax.swing.text.BadLocationException;
import javax.swing.text.StyledDocument;

import oracle.jrockit.jfr.ActiveSettingEvent;

public class Temp extends JFrame {

    JTextPane textPane;
    AbstractDocument doc;
    JTextArea changeLog;
    String newline = "\n";
    private JComboBox suggestionComboBox;
    private JPanel suggestionPanel;
    private JLabel suggestionLabel;
    private JButton openButton, saveButton, aboutButton;

    public Temp() {
        super("Snort Ruleset IDE");
        //Create the text pane and configure it.
        textPane = new JTextPane();
        textPane.setCaretPosition(0);
        textPane.setMargin(new Insets(5, 5, 5, 5));
        StyledDocument styledDoc = textPane.getStyledDocument();
        if (styledDoc instanceof AbstractDocument) {
            doc = (AbstractDocument) styledDoc;
            //doc.setDocumentFilter(new DocumentSizeFilter(MAX_CHARACTERS));
        } else {
            System.err.println("Text pane's document isn't an AbstractDocument!");
            System.exit(-1);
        }
        JScrollPane scrollPane = new JScrollPane(textPane);
        scrollPane.setPreferredSize(new Dimension(700, 350));

        //Create the text area for the status log and configure it.
        //changeLog = new JTextArea(10, 30);
        //changeLog.setEditable(false);
        //JScrollPane scrollPaneForLog = new JScrollPane(changeLog);

        //Create a JPanel for the suggestion area
        suggestionPanel = new JPanel(new BorderLayout());
        suggestionPanel.setVisible(true);
        suggestionLabel = new JLabel("Suggestion is not active at the moment.");
        suggestionLabel.setPreferredSize(new Dimension(100, 50));
        suggestionLabel.setMaximumSize(new Dimension(100, 50));
        suggestionComboBox = new JComboBox();
        suggestionComboBox.setEditable(false);
        suggestionComboBox.setPreferredSize(new Dimension(25, 25));
        //suggestionComboBox.addActionListener(new SuggestionComboBoxListener());
        suggestionComboBox.addItemListener(new SuggestionComboBoxListener());
        //suggestionComboBox.setSelectedIndex(-1);

        //add the suggestionLabel and suggestionComboBox to pane
        suggestionPanel.add(suggestionLabel, BorderLayout.CENTER);
        suggestionPanel.add(suggestionComboBox, BorderLayout.PAGE_END);
        JScrollPane sp = new JScrollPane(suggestionPanel);
        JScrollPane scrollPaneForSuggestion = new JScrollPane(suggestionPanel);

        //Create a split pane for the change log and the text area.
        JSplitPane splitPane = new JSplitPane(
                JSplitPane.VERTICAL_SPLIT,
                scrollPane, scrollPaneForSuggestion);
        splitPane.setOneTouchExpandable(true);
        splitPane.setResizeWeight(1.0);
        //Disables the moving of divider
        splitPane.setEnabled(false);

        //splitPane.setDividerLocation(splitPane.getHeight());
        //splitPane.setPreferredSize(new Dimension(640,400));

        //Create the status area.
        JPanel statusPane = new JPanel(new GridLayout(1, 1));
        CaretListenerLabel caretListenerLabel =
                new CaretListenerLabel("Status: Ready");
        statusPane.add(caretListenerLabel);

        //Create the toolbar
        JToolBar toolBar = new JToolBar();
        toolBar.setFloatable(false);
        toolBar.setRollover(true);

        openButton = new JButton("Open Snort Ruleset");
        toolBar.add(openButton);
        saveButton = new JButton("Save Ruleset");
        toolBar.add(saveButton);
        toolBar.addSeparator();
        aboutButton = new JButton("About");
        toolBar.add(aboutButton);

        //Add the components.
        getContentPane().add(toolBar, BorderLayout.PAGE_START);
        getContentPane().add(splitPane, BorderLayout.CENTER);
        getContentPane().add(statusPane, BorderLayout.PAGE_END);

        JMenu editMenu = createEditMenu();
        JMenu styleMenu = createStyleMenu();
        JMenuBar mb = new JMenuBar();
        mb.add(editMenu);
        mb.add(styleMenu);
        setJMenuBar(mb);


        //Put the initial text into the text pane.
        //initDocument();
        textPane.setCaretPosition(0);

        //Start watching for undoable edits and caret changes.
        textPane.addCaretListener(caretListenerLabel);

        SwingUtilities.invokeLater(new Runnable() {

            public void run() {
                textPane.requestFocusInWindow();
            }
        });

    }

    //This listens for and reports caret movements.
    protected class CaretListenerLabel extends JLabel
            implements CaretListener {

        public CaretListenerLabel(String label) {
            super(label);
        }

        //Might not be invoked from the event dispatch thread.
        public void caretUpdate(CaretEvent e) {
            caretInvoke(e.getDot(), e.getMark());
        }

        protected void caretInvoke(final int dot, final int mark) {
            SwingUtilities.invokeLater(new Runnable() {

                public void run() {
                    try {
                        Rectangle caretCoords = textPane.modelToView(dot);
                                    //Find suggestion
                                        suggestionComboBox.removeAllItems();
                                        for (int i = 0; i < 5; i++) {
                                            suggestionComboBox.addItem(Integer.toString(i));
                                        }
                                        //suggestionComboBox.setSelectedItem(null);
                                        suggestionComboBox.setEnabled(true);
                                        suggestionLabel.setText("The following keywords are normally used as well. Click to use keyword(s). ");
                                        //changeLog.setText("The following keywords are suggested to be used together: " + str);
                    } catch (BadLocationException ble) {
                        setText("caret: text position: " + dot + newline);
                        System.out.println("Bad Location Exception");
                    }
                }
            });
        }
    }

    public class SuggestionComboBoxListener implements ItemListener {

        //public void actionPerformed(ActionEvent e) {
        public void itemStateChanged(ItemEvent e) {
            if (e.getStateChange() == ItemEvent.SELECTED) {
                JComboBox cb = (JComboBox)e.getSource();
                String selection = (String) cb.getSelectedItem();
                JOptionPane.showMessageDialog(null, "Item is selected", "Information", JOptionPane.INFORMATION_MESSAGE);
            }
        }
    }

    /*
     * Menu Creation
     */
    //Create the edit menu.
    protected JMenu createEditMenu() {
        JMenu menu = new JMenu("Edit");
        return menu;
    }

    protected JMenu createStyleMenu() {
        JMenu menu = new JMenu("Style");
        return menu;
    }

    private static void createAndShowGUI() {
        //Create and set up the window.
        final Temp frame = new Temp();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

    //The standard main method.
    public static void main(String[] args) {
        //Schedule a job for the event dispatch thread:
        //creating and showing this application's GUI.
        SwingUtilities.invokeLater(new Runnable() {

            public void run() {
                //Turn off metal's use of bold fonts
                UIManager.put("swing.boldMetal", Boolean.FALSE);
                createAndShowGUI();
            }
        });
    }
}