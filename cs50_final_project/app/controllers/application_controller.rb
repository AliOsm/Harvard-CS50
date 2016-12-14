class ApplicationController < ActionController::Base
  protect_from_forgery with: :exception
  before_action :configure_permitted_parameters, if: :devise_controller?

  def require_admin!
    authenticate_user!

    if current_user && !current_user.admin?
      redirect_to root_path, alert: 'You don\'t have permissions.'
    end
  end
  helper_method :require_admin!

protected

  def configure_permitted_parameters
    added_attrs = [:username, :password, :password_confirmation, :remember_me]
    devise_parameter_sanitizer.permit :sign_in, keys: added_attrs
    devise_parameter_sanitizer.permit :sign_up, keys: added_attrs
    devise_parameter_sanitizer.permit :account_update, keys: added_attrs
  end
end
