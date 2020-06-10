import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.event.*;
import javafx.geometry.*;
public class FactorialJavaFX extends Application
{
public static void main(String[] args)
{
launch(args);
}
public void start(Stage myStage)
{
myStage.setTitle("Factorial");
FlowPane root = new FlowPane(100 , 100);
Scene myScene = new Scene(root , 500 , 300);
Label lbl = new Label("Enter a Number");
Label Result = new Label("");
TextField tf = new TextField("Enter the number");
EventHandler<ActionEvent> event = new EventHandler<ActionEvent>() {
public void handle(ActionEvent e)
{
int r = 1;
int t = Integer.parseInt(tf.getText());
for (int i = t ; i > 0 ; i--)
	r = r * i; 
Result.setText(""+t+"! = "+r);
}
};
tf.setOnAction(event);
root.getChildren().add(lbl);
root.getChildren().add(tf);
root.getChildren().add(Result);
myStage.setScene(myScene);
myStage.show();
}
}