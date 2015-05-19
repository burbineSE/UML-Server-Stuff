/*
 * file: autoComplete.js
 * authors: cburbine, nwarren, schau
 * course: 91.462 - GUI II Programming
 * email: 
 * christopher_burbine@student.uml.edu
 * nicholas_warren@student.uml.edu
 * sathaun_chau@student.uml.edu
 *
 * Description: This javascript will add auto-complete to search form.
 */
$(function() {
    //Creating json object to hold a series of arrays
    var bookinfo = {};
    bookinfo.index = new Array();
    bookinfo.title = new Array();
    bookinfo.edition = new Array();
    bookinfo.author = new Array();
    bookinfo.price = new Array();
    bookinfo.subject = new Array();
    bookinfo.class = new Array();
    bookinfo.isbn = new Array();

    /* MAIN */
    getData();
    addAutoComplete();

    //Add auto-complete on page load
    function addAutoComplete(criteria) {

        $('#find').autocomplete({
            source: bookinfo[$('#searchCriteria').val()]
        });

    }
    
    //Update auto-complete when category dropdown menu is changed
    $('#searchCriteria').change(function() {
        $('#find').autocomplete({
            source: bookinfo[$('#searchCriteria').val()]
        });
    });

    //Get bookinformation using php script. Book information will be stored in 
    //arrays for use with auto-complete widget
    function getData() {

        jQuery.ajax(
                {
                    async: false,
                    dataType: "json",
                    url: "php/autoComplete.php",
                    success: function(data) {
                        for (var i = 0; i < data.length; i++) {
                            bookinfo.index.push(data[i].index);
                            bookinfo.title.push(data[i].title);
                            bookinfo.edition.push(data[i].edition);
                            bookinfo.author.push(data[i].author);
                            bookinfo.price.push(data[i].price);
                            bookinfo.subject.push(data[i].subject_number);
                            bookinfo.class.push(data[i].class_number);
                            bookinfo.isbn.push(data[i].isbn);
                        }
                    },
                    error: function() {
                        console.log("ajax failed");
                    }
                }
        );


    }

});




