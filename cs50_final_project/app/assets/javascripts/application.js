// This is a manifest file that'll be compiled into application.js, which will include all the files
// listed below.
//
// Any JavaScript/Coffee file within this directory, lib/assets/javascripts, vendor/assets/javascripts,
// or any plugin's vendor/assets/javascripts directory can be referenced here using a relative path.
//
// It's not advisable to add code directly here, but if you do, it'll appear at the bottom of the
// compiled file. JavaScript code in this file should be added after the last require_* statement.
//
// Read Sprockets README (https://github.com/rails/sprockets#sprockets-directives) for details
// about supported directives.
//
//= require jquery
//= require jquery_ujs
//= require turbolinks
//= require_tree .

function MyPopUpWin(url, width, height) {
  var leftPosition, topPosition;
  leftPosition = (window.screen.width / 2) - ((width / 2) + 10);
  topPosition = (window.screen.height / 2) - ((height / 2) + 50);
  window.open(url, "",
  "status=no,height=" + height + ",width=" + width + ",resizable=yes,left="
  + leftPosition + ",top=" + topPosition + ",screenX=" + leftPosition + ",screenY="
  + topPosition + ",toolbar=no,menubar=no,scrollbars=no,location=no,directories=no");
}
