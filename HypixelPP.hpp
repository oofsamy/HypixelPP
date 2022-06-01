#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cpr/cpr.h>
#include "nlohmann.hpp"
#include <fmt/core.h>

namespace Hypixel {
	enum class ERank {
		ADMIN,
		MODERATOR,
		HELPER,
		NORMAL,
	};

	enum class EPackageRank {
		MVP_PLUS,
		MVP,
		VIP_PLUS,
		VIP,
		NONE
	};
	
	enum class EMonthlyPackageRank {
		SUPERSTAR,
		NONE
	};

	enum class ECategory {
		CONSUMABLES,
		MISC,
		ARMOR,
		ACCESSORIES,
		WEAPON,
		BLOCKS,
	};
	
	enum ETier {
		COMMON,
		UNCOMMON,
		RARE,
		EPIC,
		LEGENDARY,
		MYTHIC,
		SPECIAL,
	};

	struct Friend {
		std::string FriendID;
		std::string UUIDSender;
		std::string UUIDReciever;
		uint64_t Started;
	};
	
	struct Game {
		uint64_t Date;
		std::string GameType;
		std::string Mode;
		std::string Map;
		uint64_t Ended;
	};

	struct Session {
		bool Online;
		std::string GameType;
		std::string Mode;
		std::string Map;
	};

	struct GuildMember {
		std::string UUID;
		std::string GuildRank;
		uint64_t Joined;
		uint16_t QuestParticipation;
		//MAP OR SOMETHING 
		//"expHistory": {
		//	"2022-05-15": 1699,
		//		"2022-05-14" : 12470,
		//		"2022-05-13" : 15765,
		//		"2022-05-12" : 11172,
		//		"2022-05-11" : 3883,
		//		"2022-05-10" : 0,
		//		"2022-05-09" : 0
		//}
	};

	struct GuildRank {
		std::string Name;
		bool Default;
		uint8_t Priority;
		uint64_t Created;
	};

	struct AuctionBid {
		std::string AuctionID;
		std::string BidderUUID;
		std::string ProfileID;
		uint32_t Amount;
		uint64_t Timestamp;
	};

	struct Auction {
		std::string UUID;
		std::string AuctionerUUID;
		std::string ProfileID;
		std::vector<std::string> Coop;
		uint64_t Start;
		uint64_t End;
		std::string ItemName;
		std::string ItemLore;
		//UNKNOWN STRING: EXTRA "Enchanted Book Enchanted Book Rejuvenate"
		ECategory Category;
		ETier Tier;
		uint32_t StartingBid;
		//STRING BYTES, NEED NBT PARSER
		bool Claimed;
		std::vector<std::string> ClaimedBidders;
		uint32_t HighestBidAmount;
		uint64_t LastUpdated;
		bool Bin;
		std::vector<AuctionBid> Bids;
		std::string ItemUUID;

		std::string ToString() { return fmt::format("UUID: {}\nAuctioneer: {}\nProfile ID: {}\n"); }
	};

	struct BazaarSummary {
		uint32_t Amount;
		uint32_t PricePerUnit;
		uint32_t Orders;

		std::string ToString() { return fmt::format("Amount: {}\nPrice Per Unit: {}\nOrders: {}\n", Amount, PricePerUnit, Orders); }
	};

	struct BazaarQuickStatus {
		std::string ProductID;
		uint32_t SellPrice;
		uint32_t SellVolume;
		uint32_t SellMovingWeek;
		uint32_t SellOrders;
		uint32_t BuyPrice;
		uint32_t BuyVolume;
		uint32_t BuyMovingWeek;
		uint32_t BuyOrders;

		std::string ToString() {
			return fmt::format("Product ID: {}\nSell Price: {}\nSell Volume: {}\nSell Moving Week: {}\nSell Orders: {}\nBuy Price: {}\nBuy Volume:{}Buy Moving Week: {}\nBuy Orders: {}", 
								ProductID, SellPrice, SellVolume, SellMovingWeek, SellOrders, BuyPrice, BuyVolume, BuyMovingWeek, BuyOrders);
		}
	};

	struct Product {
		std::string ProductID;
		std::vector<BazaarSummary> SellSummary;
		std::vector<BazaarSummary> BuySummary;

		BazaarQuickStatus QuickStatus;
	};

	struct BaseResult {
		uint8_t StatusCode;
		std::string Cause;

		std::string ToStringBase() { if (StatusCode < 200 || StatusCode > 299) { return fmt::format("Status Code: {}\nCause: {}"); } else { return fmt::format("Status Code: {}", StatusCode); } }
	};

	struct KeyInfoResult : BaseResult {
		std::string Key;
		std::string Owner;
		uint16_t Limit;
		uint16_t QueriesInPastMinute;
		uint16_t TotalQueries;

		std::string ToString() { return fmt::format("Key: {}\nOwner: {}\nLimit: {}\nQueries In Past Minute: {}\nTotal Queries: {}", Key, Owner, Limit, QueriesInPastMinute, TotalQueries); }
	};

	struct PlayerDataResult : BaseResult {
		std::string UUID;
		std::string DisplayName;
		ERank Rank;
		EPackageRank CurrentPackageRank;
		EPackageRank NewPackageRank;
		EMonthlyPackageRank MonthlyPackageRank;
		uint64_t FirstLogin;
		uint64_t LastLogin;
		uint64_t LastLogout;
		//UNKNOWN STATS ARRAY
	};

	struct FriendsResult : BaseResult {
		std::string UUID;
		std::vector<Friend> Friends;
	};

	struct RecentGamesResult : BaseResult {
		std::string UUID;
		std::vector<Game> Games;

		std::string ToString() {
			std::string Temp;
			for (Hypixel::Game& G : Games) {
				Temp = Temp + (fmt::format("\n\nDate: {}\nGame Type: {}\nMode: {}\nMap: {}\nEnded: {}", G.Date, G.GameType, G.Mode, G.Map, G.Ended));
			}

			return fmt::format("UUID: {}{}", UUID, Temp);
		}
	};


	struct OnlineStatusResult : BaseResult {
		std::string UUID;
		Session Session;
	};

	struct GuildInformationResult : BaseResult {
		std::string GuildID;
		std::string Name;
		std::string NameLowered;
		uint32_t Coins;
		uint32_t CoinsEver;
		uint64_t Created;
		std::vector<GuildRank> Ranks;
		//ACHIEVEMENTS ARRAY
		uint32_t Experience;
	};

	struct SkywarsDataResult : BaseResult {
		std::string Key;
		uint32_t Position;
		uint32_t Score;
	};

	struct AuctionsDataResult : BaseResult {
		uint32_t Page;
		uint32_t TotalPages;
		uint32_t TotalAuctions;
		uint64_t LastUpdated;
		std::vector<Auction> Auctions;

		std::string ToString() { return fmt::format("Page: {}\nTotalPages: {}\nTotalAuctions: {}\nLastUpdated: {}", Page, TotalPages, TotalAuctions, LastUpdated); }
	};

	struct BazaarDataResult : BaseResult {
		uint64_t LastUpdated;
		std::vector<Product> Products;

		std::string ToString() { 
			std::string Temp;

			for (Hypixel::Product Pr : Products) {
				Temp = Temp + fmt::format("Product ID: {}\nBuy Summaries:\n\n", Pr.ProductID);

				for (Hypixel::BazaarSummary Buy : Pr.BuySummary) { Temp = Temp + Buy.ToString() + "\n"; }

				Temp = Temp + "Sell Summaries:\n\n";

				for (Hypixel::BazaarSummary Sell : Pr.SellSummary) { Temp = Temp + Sell.ToString() + "\n"; }

				Temp = Temp + Pr.QuickStatus.ToString();
			}

			return fmt::format("LastUpdated: {}\n{}", LastUpdated, Temp);
		}
	};

}

class HypixelAPI {
private:
	std::string m_APIKEY;
public:
	HypixelAPI(std::string APIKEY) : m_APIKEY(APIKEY) {};

	std::string GetAPIKEY() {
		return m_APIKEY;
	}
	
	Hypixel::KeyInfoResult GetKeyInformation() {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/key" },
			cpr::Parameters{ { "key" , GetAPIKEY() } });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::KeyInfoResult R;
			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];
			return R;
		}
		else {
			Hypixel::KeyInfoResult R{};
			R.StatusCode = r.status_code;
			R.Key = Result["record"]["key"];
			R.Owner = Result["record"]["owner"];
			R.Limit = Result["record"]["limit"];
			R.QueriesInPastMinute = Result["record"]["queriesInPastMin"];
			R.TotalQueries = Result["record"]["totalQueries"];

			return R;
		}
	}

	static Hypixel::KeyInfoResult GetKeyInformation(std::string Key) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/key" },
								   cpr::Parameters{ { "key" , Key } });

		const auto Result = nlohmann::json::parse(r.text);
		
		if (Result["success"] == false) {
			Hypixel::KeyInfoResult R;
			R.StatusCode = r.status_code;
			R.Cause = Result["record"]["cause"];
			return R;
		}
		else {
			Hypixel::KeyInfoResult R{};
			R.StatusCode = r.status_code;

			R.Key = Result["record"]["key"];
			R.Owner = Result["record"]["owner"];
			R.Limit = Result["record"]["limit"];
			R.QueriesInPastMinute = Result["record"]["queriesInPastMin"];
			R.TotalQueries = Result["record"]["totalQueries"];

			return R;
		}
	};
	
	Hypixel::PlayerDataResult GetPlayerDataInformation(std::string UUID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/player" },
								   cpr::Parameters{ { "key" , m_APIKEY } ,{"uuid", UUID} });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::PlayerDataResult R;
			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];
			return R;
		}
		else {
			Hypixel::PlayerDataResult R{};
			R.StatusCode = r.status_code;

			R.UUID = Result["uuid"];
			R.DisplayName = Result["displayname"];

			if (Result["rank"] == "ADMIN") {
				R.Rank = Hypixel::ERank::ADMIN;
			} else if (Result["rank"] == "MODERATOR") {
				R.Rank = Hypixel::ERank::MODERATOR;
			} else if (Result["rank"] == "HELPER") {
				R.Rank = Hypixel::ERank::HELPER;
			} else if (Result["rank"] == "NORMAL") {
				R.Rank = Hypixel::ERank::NORMAL;
			}

			if (Result["packageRank"] == "MVP_PLUS") {
				R.CurrentPackageRank = Hypixel::EPackageRank::MVP_PLUS;
			} else if (Result["packageRank"] == "MVP") {
				R.CurrentPackageRank = Hypixel::EPackageRank::MVP;
			} else if (Result["packageRank"] == "VIP_PLUS") {
				R.CurrentPackageRank = Hypixel::EPackageRank::VIP_PLUS;
			} else if (Result["packageRank"] == "VIP") {
				R.CurrentPackageRank = Hypixel::EPackageRank::VIP;
			} else if (Result["packageRank"] == "NONE") {
				R.CurrentPackageRank = Hypixel::EPackageRank::NONE;
			}

			if (Result["newPackageRank"] == "MVP_PLUS") {
				R.NewPackageRank = Hypixel::EPackageRank::MVP_PLUS;
			} else if (Result["newPackageRank"] == "MVP") {
				R.NewPackageRank = Hypixel::EPackageRank::MVP;
			} else if (Result["newPackageRank"] == "VIP_PLUS") {
				R.NewPackageRank = Hypixel::EPackageRank::VIP_PLUS;
			} else if (Result["newPackageRank"] == "VIP") {
				R.NewPackageRank = Hypixel::EPackageRank::VIP;
			} else if (Result["newPackageRank"] == "NONE") {
				R.NewPackageRank = Hypixel::EPackageRank::NONE;
			}
			
			if (Result["monthlyPackageRank"] == "SUPERSTAR") {
				R.MonthlyPackageRank = Hypixel::EMonthlyPackageRank::SUPERSTAR;
			} else if (Result["monthlyPackageRank"] == "NONE") {
				R.MonthlyPackageRank = Hypixel::EMonthlyPackageRank::NONE;
			}
			
			
			R.FirstLogin = Result["firstLogin"];
			R.LastLogin = Result["lastLogin"];
			R.LastLogout = Result["lastLogout"];

			return R;
		}
	}

	Hypixel::FriendsResult GetFriendsOfUserResult(std::string UUID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/friends" },
								   cpr::Parameters{ { "key" , m_APIKEY } ,{"uuid", UUID} });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::FriendsResult R;

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::FriendsResult R{};

			R.StatusCode = r.status_code;
			R.UUID = Result["uuid"];

			for (int i = 0; i < Result["records"].size(); i++) {
				Hypixel::Friend F{};

				F.FriendID = Result["records"][i]["_id"];
				F.UUIDSender = Result["records"][i]["uuidSender"];
				F.UUIDReciever = Result["records"][i]["uuidReceiver"];
				F.Started = Result["records"][i]["started"];

				R.Friends.push_back(F);
			}

			return R;
		}
	}

	Hypixel::RecentGamesResult GetRecentGamesPlayed(std::string UUID) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/recentgames" },
								   cpr::Parameters{ {"key", m_APIKEY}, {"uuid", UUID} });
		
		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::RecentGamesResult R{};

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::RecentGamesResult R{};

			R.StatusCode = r.status_code;
			R.UUID = Result["uuid"];
			
			for (int i = 0; i < Result["games"].size(); i++) {
				Hypixel::Game Game{};

				Game.Date = Result["games"][i]["date"];
				Game.GameType = Result["games"][i]["gameType"];
				Game.Mode = Result["games"][i]["mode"];
				Game.Map = Result["games"][i]["map"];
				Game.Ended = Result["games"][i]["ended"];

				R.Games.push_back(Game);
			}

			return R;
		}
	}

	static Hypixel::AuctionsDataResult GetAuctionData(int Page) {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/skyblock/auctions" },
								               cpr::Parameters{ {"page", std::to_string(Page)}});

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::AuctionsDataResult R;

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::AuctionsDataResult R;

			R.StatusCode = r.status_code;
			R.Page = Result["page"];
			R.TotalPages = Result["totalPages"];
			R.TotalAuctions = Result["totalAuctions"];
			R.LastUpdated = Result["lastUpdated"];
			
			for (int i = 0; i < Result["auctions"].size(); i++) {
				Hypixel::Auction A{};

				auto AuctionResult = Result["auctions"][i];

				A.UUID = AuctionResult["uuid"];
				A.AuctionerUUID = AuctionResult["auctioneer"];
				A.ProfileID = AuctionResult["profile_id"];
				//A.Coop
				A.Start = AuctionResult["start"];
				A.End = AuctionResult["end"];
				A.ItemName = AuctionResult["item_name"];
				A.ItemLore = AuctionResult["item_lore"];
				A.StartingBid = AuctionResult["starting_bid"];
				A.LastUpdated = AuctionResult["last_updated"];
				A.Bin = AuctionResult["bin"];

				R.Auctions.push_back(A);
			}

			return R;
		}
	}

	static Hypixel::BazaarDataResult GetBazaarInformation() {
		cpr::Response r = cpr::Get(cpr::Url{ "https://api.hypixel.net/skyblock/bazaar" });

		const auto Result = nlohmann::json::parse(r.text);

		if (Result["success"] == false) {
			Hypixel::BazaarDataResult R{};

			R.StatusCode = r.status_code;
			R.Cause = Result["cause"];

			return R;
		} else {
			Hypixel::BazaarDataResult R{};

			R.StatusCode = r.status_code;
			R.LastUpdated = Result["lastUpdated"];

			for (auto& ProductItem : Result["products"].items()) {
				Hypixel::Product Pr{};

				const auto Product = Result["products"][ProductItem.key()];
				
				Pr.ProductID = Product["product_id"];

				for (int i = 0; i < Product["sell_summary"].size(); i++) {
					Hypixel::BazaarSummary SellSummary{};

					SellSummary.Amount = Product["sell_summary"][i]["amount"];
					SellSummary.PricePerUnit = Product["sell_summary"][i]["pricePerUnit"];
					SellSummary.Orders = Product["sell_summary"][i]["orders"];

					Pr.SellSummary.push_back(SellSummary);
				}

				for (int i = 0; i < Product["buy_summary"].size(); i++) {
					Hypixel::BazaarSummary BuySummary{};

					BuySummary.Amount = Product["buy_summary"][i]["amount"];
					BuySummary.PricePerUnit = Product["buy_summary"][i]["pricePerUnit"];
					BuySummary.Orders = Product["buy_summary"][i]["orders"];

					Pr.BuySummary.push_back(BuySummary);
				}

				Hypixel::BazaarQuickStatus QuickStatus{};

				QuickStatus.ProductID = Product["quick_status"]["productId"];
				QuickStatus.SellPrice = Product["quick_status"]["sellPrice"];
				QuickStatus.SellVolume = Product["quick_status"]["sellVolume"];
				QuickStatus.SellMovingWeek = Product["quick_status"]["sellMovingWeek"];
				QuickStatus.SellOrders = Product["quick_status"]["sellOrders"];
				QuickStatus.BuyPrice = Product["quick_status"]["buyPrice"];
				QuickStatus.BuyVolume = Product["quick_status"]["buyVolume"];
				QuickStatus.BuyMovingWeek = Product["quick_status"]["buyMovingWeek"];
				QuickStatus.BuyOrders = Product["quick_status"]["buyOrders"];

				Pr.QuickStatus = QuickStatus;

				R.Products.push_back(Pr);
			}

			return R;
		}
	}
};

namespace Hypixel::Utils {
	std::string UsernameToUUID(std::string Username) {
		cpr::Response r = cpr::Get("https://api.mojang.com/users/profiles/minecraft/" + Username);
		return nlohmann::json::parse(r.text)["id"];
	}

	std::string UUIDToUsername(std::string UUID) {
		cpr::Response r = cpr::Get("https://api.mojang.com/user/profiles/" + UUID + "/names");
		return nlohmann::json::parse(r.text)[0];
	}
}
