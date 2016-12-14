class Admin::BaseController < ApplicationController
  before_action :require_admin!

  layout 'admin'

  def home
    @last_signups = User.last_signups(10)
    @last_signins = User.last_signins(10)
    @users_count = User.users_count
    @admins = User.admins
  end
end
