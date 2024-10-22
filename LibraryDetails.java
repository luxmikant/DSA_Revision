import java.time.LocalDate;
import java.time.Period;

interface LibraryDetails {
    String bookName = "";
    String bookTitle = "";
    String accType = "";
    String date = "";
    double bal = 0.0;
}

class Book implements LibraryDetails {
    String bookName;
    String bookTitle;
    String accType;
    String date;
    double bal;

    Book(String bookName, String bookTitle, String accType, String date, double bal) {
        this.bookName = bookName;
        this.bookTitle = bookTitle;
        this.accType = accType;
        this.date = date;
        this.bal = bal;
    }

    void calculateReturnDate() {
        String[] dateArray = date.split("-");
        int year = Integer.parseInt(dateArray[0]);
        int month = Integer.parseInt(dateArray[1]);
        int day = Integer.parseInt(dateArray[2]);

        LocalDate localDate = LocalDate.of(year, month, day);
        LocalDate returnDate = localDate.plusDays(15);

        System.out.println("Return Date: " + returnDate.getYear() + "-" + returnDate.getMonthValue() + "-" + returnDate.getDayOfMonth());
    }

    void calculateFineAmount() {
        String[] dateArray = date.split("-");
        int year = Integer.parseInt(dateArray[0]);
        int month = Integer.parseInt(dateArray[1]);
        int day = Integer.parseInt(dateArray[2]);

        LocalDate localDate = LocalDate.of(year, month, day);
        LocalDate currentDate = LocalDate.now();

        Period period = Period.between(localDate, currentDate);
        int days = period.getDays();

        if (days > 15) {
            double fine = (days - 15) * 0.5;
            System.out.println("Fine Amount: $" + fine);
        } else {
            System.out.println("No fine");
        }
    }

    void displayDetails() {
        System.out.println("Book Name: " + bookName);
        System.out.println("Book Title: " + bookTitle);
        System.out.println("Account Type: " + accType);
        System.out.println("Date: " + date);
        System.out.println("Balance: $" + bal);
    }
}

public class Main {
    public static void main(String[] args) {
        Book book = new Book("Java Programming", "Introduction to Java", "Student", "2022-01-01", 100.0);

        book.displayDetails();
        book.calculateReturnDate();
        book.calculateFineAmount();
    }
}