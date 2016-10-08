$(document).ready(function repaintContent() {
    $("#SearchPanel").load('searchpanel.html');
    $("#Dashboard").load('dashboard.html').hide();
    $("#EditProfile").load('editprofile.html').hide();
    $("#Contact").load('contact.html').hide();
    $("#About").load('about').hide();
    $("#Footer").load('footer.html');
    $("#resultsDiv").hide();
});
$(function() {
    $("#DashboardButton").click(function (event) {
        //$.hideEverything();
        $("#SearchPanel").hide();
        $("#EditProfile").hide();
        $("#Dashboard").show();
        $("#Contact").hide();
        $("#About").hide();
        event.preventDefault();
    });

    $("#index").click(function (event) {
        location.reload();
        event.preventDefault();
    });

    $("#ContactButton").click(function (event) {
        $("#SearchPanel").hide();
        $("#Dashboard").hide();
        $("#EditProfile").hide();
        $("#Contact").show();
        $("#About").hide();
        event.preventDefault();
    });

    $("#AboutButton").click(function (event) {
        $("#SearchPanel").hide();
        $("#Dashboard").hide();
        $("#EditProfile").hide();
        $("#Contact").hide();
        $("#About").show();
        event.preventDefault();
    });

    $("#EditProfileButton").click(function (event) {
        $("#SearchPanel").hide();
        $("#Dashboard").hide();
        $("#EditProfile").show();
        $("#Contact").hide();
        $("#About").hide();
        event.preventDefault();
    });

});