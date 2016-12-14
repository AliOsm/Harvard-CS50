class User < ApplicationRecord
  include Tokenable
  has_many :markers, dependent: :destroy

  paginates_per 100

  # Include default devise modules. Others available are:
  # :confirmable, :lockable, :timeoutable, :recoverable and :omniauthable
  devise :database_authenticatable, :registerable,
  			 :rememberable, :trackable, :validatable

  validates :username, presence: :true
  validates :username, uniqueness: { case_sensitive: false }
  validates :username, length: { in: 3..16 }
  validates_format_of :username, with: /\A[a-zA-Z0-9\_]*\z/

  def self.search_and_order(search, page_number, order_options)
    order_options = 'id' if order_options.blank?

    if search
      where("username LIKE ?", "%#{search.downcase}%").order(admin: :desc, username: :asc).page page_number
    else
      order(order_options.parameterize.underscore.to_sym => :desc).page page_number
    end
  end

  def self.last_signups(count)
    order(created_at: :desc).limit(count).select("id", "username", "created_at")
  end

  def self.last_signins(count)
    order(last_sign_in_at: :desc).limit(count).select("id", "username", "last_sign_in_at")
  end

  def self.users_count
    where("admin = ?", false).count
  end

  def self.admins
    where("admin = ?", true).order(id: :asc)
  end

  def email_required?
  	false
  end

	def email_changed?
		false
	end
end
