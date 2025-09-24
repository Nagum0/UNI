package printed.material;

public class Book {
    public static final String defaultAuthor = "John Steinbeck";
    public static final String defaultTitle = "Of Mice and Men";  
    public static final int defaultPageCount = 107;
    private String author;
    private String title;
    protected int pageCount;

    public Book() {
        this(defaultAuthor, defaultTitle, defaultPageCount);
    }

    public Book(String author, String title, int pageCount) {
        try {
            checkInitData(author, title, pageCount);
            initBook(author, title, pageCount);
    
        }
        catch (IllegalArgumentException e) {
            initBook(defaultAuthor, defaultTitle, defaultPageCount);
        }
    }

    private void checkInitData(String author, String title, int pageCount) {
        if (author.length() < 2 || title.length() < 4 || pageCount <= 0)
            throw new IllegalArgumentException("Illegal book data!");
    }

    /* ??? */
    public String createReference(String idk, int idk2, int idk3) {
        return "";
    }

    public static Book decode(String bookData) {
        String[] splitData = bookData.split(",");

        for (int i = 0; i < splitData.length; i++)
            splitData[i] = splitData[i].strip();
        
        return new Book(splitData[0], splitData[1], Integer.parseInt(splitData[2]));
    }

    protected String getAuthorWithInitials() {
        StringBuilder sbr = new StringBuilder();
        
        sbr.append(author.charAt(0) + ". " + author.split(" ")[1]);

        return sbr.toString();
    }

    public int getPrice() {
        return pageCount;
    }

    public String getShortInfo() {
        StringBuilder sbr = new StringBuilder();
        
        sbr.append(getAuthorWithInitials() + ": ");
        sbr.append(title.substring(0, 4) + "; ");
        sbr.append(pageCount);

        return sbr.toString();
    }  

    protected void initBook(String author, String title, int pageCount) {
        this.author = author;
        this.title = title;
        this.pageCount = pageCount;
    }

    public String getAuthor() {
        return author;
    }

    public String getTitle() {
        return title;
    }

    public int getPageCount() {
        return pageCount;
    }

    @Override
    public String toString() {
        return author + ": " + title + "; " + pageCount;
    }
}