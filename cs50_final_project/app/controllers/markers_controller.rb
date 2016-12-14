class MarkersController < ApplicationController
  before_action :set_marker, only: [:destroy]

  # POST /markers
  # POST /markers.json
  def create
    @marker = current_user.markers.new(marker_params)

    respond_to do |format|
      if @marker.save
        format.html { redirect_to dashboard_path, notice: 'Marker was successfully created.' }
        format.js { render :show, locals: { action: true, id: @marker.id, lat: @marker.lat, lng: @marker.lng, title: @marker.title, description: @marker.description } }
      else
        format.html { redirect_to dashboard_path, notice: 'Marker was not created.' }
        format.js { render :show, locals: { action: false } }
      end
    end
  end

  # DELETE /markers/1
  # DELETE /markers/1.json
  def destroy
    @marker.destroy
    markers = current_user.markers.all
    respond_to do |format|
      format.html { redirect_to dashboard_path, notice: 'Marker was successfully destroyed.' }
      format.js { render :destroy, locals: { markers: markers } }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_marker
      @marker = current_user.markers.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def marker_params
      params.require(:marker).permit(:lat, :lng, :title, :description, :user_id)
    end
end
