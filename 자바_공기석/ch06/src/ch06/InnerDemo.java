package ch06;
public class InnerDemo {
    class MemberClass {

    }
    interface MemberInterface{

    }
    public static void main(String[] args){
        class LocalClass{

        }
    }
    static void foo(){
        class LocalClass{

        }
    }
}