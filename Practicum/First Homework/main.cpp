#include "./src/LibraryAllocator.hpp"

using namespace std;

int main()
{
    LibraryAllocator lib(6);

    Book book1 = lib.createNewBook("1111", "Title1", "A1", 1);
    lib.addBookToLibrary(book1);

    Book book2 = lib.createNewBook("2222", "Title2", "A2", 2);
    Book book3 = lib.createNewBook("3333", "Title3", "A3", 3);
    lib.addBookToLibrary(book2);
    lib.addBookToLibrary(book3);

    lib.printLibrary();
    cout << "====================================" << endl;
    lib.removeBookFromLibrary("2222");
    lib.printLibrary();

    lib.cleanAll();
    return 0;
}