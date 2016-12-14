class Admin::UsersController < Admin::BaseController
  before_action :set_user, only: [:show, :edit, :update, :destroy]

  def index
    @users = User.search_and_order(params[:search], params[:page], params[:order_options])
    @order_options = params[:order_options]
  end

  def show
    redirect_to edit_admin_user_path(params[:id])
  end

  def edit
  end

  def update
    username = @user.username
    new_params = user_params.dup
    new_params[:username] = new_params[:username].strip

    @user.username = new_params[:username]
    @user.password = new_params[:password] if new_params[:password].strip.length > 5
    @user.password_confirmation = new_params[:password_confirmation] if new_params[:password_confirmation].strip.length > 5
    @user.admin = new_params[:admin]

    respond_to do |format| 
      if @user.valid?
        @user.save
        format.html { redirect_to admin_users_path, notice: 'The user has been updated.' }
      else
        format.html { render :edit }
        format.json { render json: @user.errors, status: :unprocessable_entity }
      end
    end
  end

  def destroy
    if current_user.id != @user.id
      @user.destroy
      redirect_to admin_users_path, notice: "The user has been deleted."
    else
      redirect_to admin_users_path, alert: "You can not delete your account."
    end
  end

  private
    def set_user
      @user = User.find(params[:id])
    rescue
      flash[:alert] = "There is no user with this id #{params[:id]}."
      redirect_to admin_users_path
    end

    def user_params
      params.require(:user).permit(:username, :password, :password_confirmation, :admin)
    end
end