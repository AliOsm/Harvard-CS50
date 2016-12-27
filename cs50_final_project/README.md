# This is my CS50x final project

[Try it now!](http://imarker.herokuapp.com/)

`iMarker` it is very simple service allow you to make markers on your private map after signup and save them for years xD and you can share any of these markers individually or you can share your map to other people and tell them where you live, go, work or where is branches of your company!

`iMarker` indicate your location based on your IP Address, so if you use vpn or anything like this the map will open above your vpn IP Address.

You can contact us using this email with your feedback, ideas and suggestions: AliOsm1997@gmail.com.

----------

Programming Language: Ruby.

Frameword: Ruby on Rails.

Design: HTML, CSS and JavaScript.

CSS Framework: Bootstrap.

----------

To run this site locally you need few requirements installed on your machine:

- Ruby Programming Language version `2.3.1p112`.
- Ruby on Rails Framework version `5.0.0.1`.
- Gems:
 - `font-awesome-rails`.
 - `devise`.
 - `kaminari`.
 - `geocoder`.

after that clone this repository, run `bundle install` then `rake db:migrate` and have fun!

NOTE: You need to add one new user using seeds.rb file, you can go to seeds.rb file and replace stars `*` with your own information then run `rake db:seed`.
