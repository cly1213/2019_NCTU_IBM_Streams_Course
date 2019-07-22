package application;

@com.ibm.streams.operator.internal.model.ShadowClass("application.My_java_functionImpl")
@javax.annotation.Generated("com.ibm.streams.operator.internal.model.processors.ShadowClassGenerator")
public class My_java_functionImpl$StreamsModel {

@com.ibm.streams.function.model.Function(namespace="com.nctu.myutils", name="add", description="add two integers", stateful=true)
@com.ibm.streams.operator.internal.model.MethodParameters({"a", "b"})
public static int add(int a, int b) {return 0; }

@com.ibm.streams.function.model.Function(namespace="com.nctu.myutilx", name="cumuAdd", description="add two integers and cum result", stateful=true)
@com.ibm.streams.operator.internal.model.MethodParameters({"a", "b"})
public static int cumuAdd(int a, int b) {return 0; }

@com.ibm.streams.function.model.Function(namespace="com.nctu.myutils", name="getUser", description="return user ID", stateful=true)
@com.ibm.streams.operator.internal.model.MethodParameters({})
public static java.lang.String getUser() {return null; }
}