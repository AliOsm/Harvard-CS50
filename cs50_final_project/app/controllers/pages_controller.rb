class PagesController < ApplicationController
	before_action :authenticate_user!, only: [:dashboard, :change_token]

  def home
  	if user_signed_in?
  		redirect_to dashboard_path and return
  	end
  end

  def dashboard
    @location = Geocoder.coordinates(current_user.last_sign_in_ip)
    @markers = current_user.markers.all
    @marker = Marker.new
  end

  def user_map
    user = User.find_by_username(params[:username].downcase)
    if user.token === params[:token]
      @location = Geocoder.coordinates(user.last_sign_in_ip)
      @markers = user.markers.all
    else
      redirect_to root_path
    end
  end

  def change_token
    current_user.update_attributes(token: SecureRandom.urlsafe_base64(nil, false))

    respond_to do |format| 
      format.html { redirect_to root_path, notice: 'Your public map URL successfully changed.' }
      format.js { render :change_token }
    end
  end

  def about
  end
end
