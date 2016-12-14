Rails.application.routes.draw do
  devise_for :users

  resources :markers, only: [:create, :destroy]

  namespace :admin do
    root "base#home"
    
    resources :users, only: [:index, :show, :edit, :update, :destroy]
  end
  
  get 'home' => 'pages#home'

  get 'dashboard' => 'pages#dashboard'

  match '/:username/:token' => 'pages#user_map', via: :get

  match 'change_token' => 'pages#change_token', via: :put

  get 'about' => 'pages#about'

  root 'pages#home'

  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
