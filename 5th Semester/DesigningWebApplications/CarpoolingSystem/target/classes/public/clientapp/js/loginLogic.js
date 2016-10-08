$(document).ready(function repaintNavBar(){
		$("#LoginForm").load('login.html').hide();
		$("#RegisterForm").load('register.html').hide();

		if (sessionStorage.loggedIn == undefined) {
			sessionStorage.loggedIn = 0
		}

		if (sessionStorage.loggedIn == 1){
            $("#EditProfileButton").show();
            $("#DashboardButton").show();
            $("#LogoutButton").show();
            $("#LoginButton").hide();
            $("#RegisterButton").hide();
            $("#Username").text(sessionStorage.UserName);
		} else {
            $("#EditProfileButton").hide();
            $("#DashboardButton").hide();
            $("#LogoutButton").hide();
            $("#LoginButton").show();
            $("#RegisterButton").show();
		}
});
$(function(){
    $( "#LoginForm" ).dialog({
        autoOpen: false,
        width:600,
        modal:true
        //open: function(event, ui) { $(".ui-dialog-titlebar-close", ui.dialog | ui).hide(); }
    });

    $( "#RegisterForm" ).dialog({
        autoOpen: false,
        width:650,
        modal:true
        //open: function(event, ui) { $(".ui-dialog-titlebar-close", ui.dialog | ui).hide(); }
    });

    $( "#LoginButton" ).click(function( event ) {
        //$("#mainSite").css({background: "", opacity: 0.5});
        $( "#LoginForm" ).dialog( "open" );
        event.preventDefault();
    });

    $( "#RegisterButton" ).click(function( event ) {
        //$("#mainSite").css({background: "", opacity: 0.5});
        $( "#RegisterForm" ).dialog( "open" );
        event.preventDefault();
    });
});
function clickLogout(){
    sessionStorage.clear()
	location.reload()
}