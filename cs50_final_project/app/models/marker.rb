class Marker < ApplicationRecord
	belongs_to :user

	validates :lat, presence: :true
	validates :lng, presence: :true
	validates :title, presence: :true
	validates :title, length: { in: 1..255 }
end
