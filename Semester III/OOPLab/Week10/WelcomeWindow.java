import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;  
import javafx.scene.control.Button;  
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;  
import javafx.scene.layout.GridPane;  
import javafx.stage.Stage;  
public class WelcomeWindow extends Application
{  
public void start(Stage primaryStage) throws Exception
{  
Label FirstName = new Label("First Name : ");  
Label Password = new Label("Password : ");  
Label Result = new Label("");
TextField tf1 = new TextField();  
PasswordField tf2 = new PasswordField();  
Button Submit = new Button ("Sign in");   
GridPane root = new GridPane();  
Scene scene = new Scene(root , 500 , 500); 
root.addRow(0 , FirstName , tf1);  
root.addRow(1 , Password , tf2);  
root.addRow(2 , Submit); 
root.addRow(3 , Result); 
Submit.setOnAction(new EventHandler<ActionEvent>()
{
public void handle(ActionEvent event)
{
Result.setText("Welcome "+tf1.getText()+"!");
}
}
);
primaryStage.setScene(scene);  
primaryStage.show();  
}  
public static void main(String[] args)
{  
launch(args);  
}     
}  