import javafx.scene.control.*;
import javafx.application.Application;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.event.*;
import javafx.geometry.*;
public class JavaFXCalculator extends Application
{
public static void main(String args[])
{
launch(args);
}
public void start(Stage myStage)
{
myStage.setTitle("Calculator");
FlowPane root = new FlowPane(200,100);
root.setTextFill(Color.RED);
Scene myScene = new Scene(root,800,500);
Label lbl1 = new Label("Enter a Number : ");
TextField tf1 = new TextField();
Label lbl2 = new Label("Enter another Number : ");
TextField tf2 = new TextField();
Label sum = new Label("");
Label diff = new Label("");
Label prod = new Label("");
Label quotient = new Label("");
Button b = new Button("Compute");
EventHandler<ActionEvent> event1 = new EventHandler<ActionEvent>() {
public void handle(ActionEvent e)
{
float a = Float.parseFloat(tf1.getText());
float b = Float.parseFloat(tf2.getText());
float s = a+b;
float d = a-b;
float p = a*b;
float q = a/b;
sum.setText("Sum = "+s+"\n");
diff.setText("Difference = "+d+"\n");
prod.setText("Product = "+p+"\n");
quotient.setText("Quotient = "+q+"\n");
//sum.setText("Sum of '"+a+"' and '+b+"' = '+(a+b)+"' ");
//diff.setText("Difference of '"+a+"' and '+b+"' = '+(a-b)+"' ");
//prod.setText("Product of '"+a+"' and '+b+"' = '+(a*b)+"' ");
//quotient.setText("Quotient of '"+a+"' and '+b+"' = '+(a/b)+"' ");
}
};
b.setOnAction(event1);
root.getChildren().add(lbl1);
root.getChildren().add(tf1);
root.getChildren().add(lbl2);
root.getChildren().add(tf2);
root.getChildren().add(b);
root.getChildren().add(sum);
root.getChildren().add(diff);
root.getChildren().add(prod);
root.getChildren().add(quotient);
myStage.setScene(myScene);
myStage.show();
}
}